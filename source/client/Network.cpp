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

void Network::setThread(AThread *th)
{
  this->m_thread = th;
}

void Network::setMutex(AMutex *mutex)
{
  this->m_mutex = mutex;
}

void Network::tryConnect(void)
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
  host = this->m_model.getElementByName("TEXT_HOST")->getContent();
  port = this->m_model.getElementByName("TEXT_PORT")->getContent();
  login = this->m_model.getElementByName("TEXT_LOGIN")->getContent();
  pass = this->m_model.getElementByName("TEXT_PASSWORD")->getContent();
	try
	{
		this->m_tcpClient = new TCP_client(host, port);
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

void Network::update(void)
{
  this->m_select.want_read(*this->m_tcpClient);
  this->m_select.want_write(*this->m_tcpClient);
  if (this->m_udpClient != NULL)
    {
      this->m_select.want_read(*this->m_udpClient);
      this->m_select.want_write(*this->m_udpClient);
    }
  this->m_select.select(this->m_time);
  if (this->m_select.can_read(*this->m_tcpClient))
    this->m_tcpProto->recv(*this->m_tcpClient);
  if (this->m_udpClient != NULL)
    if (this->m_select.can_read(*this->m_udpClient))
      this->m_udpProto->recv(*this->m_udpClient);
}

void Network::loop(void)
{
  while (!this->m_end)
    {
      if (this->m_tcpClient == NULL)
	this->tryConnect();
      else
	this->update();
      this->m_mutex->lock();
      this->m_end = this->m_model.getEnd();
      this->m_mutex->unlock();
    }
}
