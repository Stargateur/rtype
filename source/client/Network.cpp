#include "Network.hpp"

Network::Network(Model &model) :
	m_model(model), m_select(*new Select), m_time(new Time), m_thread(NULL), m_mutex(NULL), m_tcpClient(NULL), m_udpClient(NULL), m_client(NULL), m_tcpProto(NULL), m_player(NULL), m_udpProto(NULL), m_end(false)
{
	this->m_time->set_second(0);
	this->m_time->set_nano(500000);
}


Network::~Network()
{
}

AThread * Network::getThread(void) const
{
  return (this->m_thread);
}

const std::string &Network::getIP(void) const
{
	return (this->m_ip);
}

void Network::setThread(AThread *th)
{
  this->m_thread = th;
}

void Network::setMutex(AMutex *mutex)
{
  this->m_mutex = mutex;
}

void Network::tryConnectTCP(void)
{
  bool canConnect;
  std::string host;
  std::string port;
  std::string login;
  std::string pass;

  this->m_mutex->lock();
  canConnect = this->m_model.canConnect();
  this->m_mutex->unlock();
  if (!canConnect)
    return;
  this->m_mutex->lock();
  this->m_ip = this->m_model.getElementByName("TEXT_HOST")->getContent();
  port = this->m_model.getElementByName("TEXT_PORT")->getContent();
  login = this->m_model.getElementByName("TEXT_LOGIN")->getContent();
  m_login = pass;
  pass = this->m_model.getElementByName("TEXT_PASSWORD")->getContent();
	try
	{
		this->m_tcpClient = new TCP_client(this->m_ip, port);
	}
	catch (const TCP_client_exception &e)
	{
		this->m_tcpClient = NULL;
		this->m_model.setConnect(false);
		this->m_mutex->unlock();
		return;
	}
  this->m_client = new Client(*this, this->m_model);
  std::cout << "Connected" << std::endl;
  m_model.setState(Model::PRINCIPAL);
  this->m_tcpProto = new TCP_protocol(*(this->m_client));
  this->m_tcpProto->send_connect(login, pass);
  this->m_mutex->unlock();
}

void Network::tryConnectUDP(const std::string &port)
{
	try
	{
		this->m_udpClient = new UDP_client(this->m_ip, port);
	}
	catch (const UDP_client_exception &error)
	{
		this->m_udpClient = NULL;
		this->m_model.setConnect(false);
		this->m_model.setState(Model::CONNEXION);
		delete (this->m_tcpClient);
		delete (this->m_tcpProto);
		delete (this->m_client);
		this->m_tcpProto = NULL;
		this->m_tcpClient = NULL;
		this->m_client = NULL;
	}
	this->m_player = new Player(this->m_model, *this);
	this->m_udpProto = new UDP_protocol(*this->m_player);
	this->m_model.setState(Model::GAME);
}

void Network::update(void)
{
  m_select.reset();
  if (m_tcpProto->want_recv() == true)
    this->m_select.want_read(*this->m_tcpClient);
  if (m_tcpProto->want_send() == true)
    this->m_select.want_write(*this->m_tcpClient);
  if (this->m_udpClient != NULL)
    {
      if (m_udpProto->want_recv() == true)
	this->m_select.want_read(*this->m_udpClient);
      if (m_udpProto->want_send() == true)
	this->m_select.want_write(*this->m_udpClient);
    }
  this->m_select.select(this->m_time);
  this->m_mutex->lock();
  if (this->m_select.can_read(*this->m_tcpClient))
    this->m_tcpProto->recv(*this->m_tcpClient);
  if (this->m_select.can_write(*this->m_tcpClient))
    this->m_tcpProto->send(*this->m_tcpClient);
  if (this->m_udpClient != NULL)
    {
    if (this->m_select.can_read(*this->m_udpClient))
      this->m_udpProto->recv(*this->m_udpClient);
    if (this->m_select.can_write(*this->m_udpClient))
      this->m_udpProto->send(*this->m_udpClient);
    }
  this->m_mutex->unlock();
}

void Network::loop(void)
{
  ITCP_protocol::Game	target;
  
  while (!this->m_end)
    {
      if (this->m_tcpClient == NULL)
	this->tryConnectTCP();
      else
	this->update();
      this->m_mutex->lock();
      if (m_model.getRefresh() == true && m_tcpClient != NULL)
	{
	  m_tcpProto->send_list_meta_games();
	  m_model.setRefresh(false);
	  std::cout << "Refresh game asked" << std::endl;
	}
      if (m_model.getJoin() == true && m_tcpClient != NULL)
	{
	  target.name = m_model.getElementByName("SERVER_TOJOIN")->getContent();
	  target.owner = m_login;
	  m_tcpProto->send_join_game(target);
	  m_model.setState(Model::LIST);
	  m_model.setJoin(false);
	  std::cout << "Join game asked" << std::endl;
	}
      if (m_model.getCreate() == true && m_tcpClient != NULL)
	{
	  target.name = m_model.getElementByName("SERVER_TOJOIN")->getContent();
	  target.owner = m_login;
	  m_tcpProto->send_create_game(target);
	  m_model.setState(Model::LIST);
	  m_model.setCreate(false);
	  std::cout << "Create game asked" << target.name << std::endl;
	}
      if (m_model.getReady() == true && m_tcpClient != NULL)
	{
	  m_tcpProto->send_list_meta_sprites();
	  m_tcpProto->send_ready(true);
	  std::cout << "Ready sent" << target.name << std::endl;
	  m_model.setReady(false);
	}
      this->m_end = this->m_model.getEnd();
      this->m_mutex->unlock();
    }
}
