//
// Client.cpp for Client in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:56:02 2015 Alaric Degand
// Last update Sun Dec 27 06:58:10 2015 Antoine Plaskowski
//

#include	"Client.hpp"

Client::Client(Server &server, ITCP_client &itcp_client) :
  m_server(server),
  m_itcp_client(itcp_client),
  m_itcp_protocol(*new TCP_protocol(*this)),
  m_last(nullptr),
  m_wait_pong(false),
  m_ready(false)
{
}

Client::~Client(void)
{
  delete &m_itcp_client;
  delete &m_itcp_protocol;
  delete m_last;
}

void	Client::pre_run(ISelect &iselect)
{
  if (m_itcp_protocol.want_recv() == true)
    iselect.want_read(m_itcp_client);
  if (m_itcp_protocol.want_send() == true)
    iselect.want_read(m_itcp_client);
}

void	Client::run(ISelect const &iselect, ITime const &timeout)
{
  if (m_last == nullptr)
    m_last = &timeout.clone();
  if (iselect.can_read(m_itcp_client) == true)
    {
      m_last->now();
      m_itcp_protocol.recv(m_itcp_client);
    }
  this->timeout(timeout);
  if (iselect.can_write(m_itcp_client) == true)
    m_itcp_protocol.send(m_itcp_client);
}

void	Client::timeout(ITime const &timeout)
{
  intmax_t      second = m_last->get_second();
  intmax_t      nano = m_last->get_nano();

  m_last->now();
  if (m_last->get_second() - second > timeout.get_second() ||
      (m_last->get_second() - second == timeout.get_second() && m_last->get_nano() - nano > timeout.get_nano()))
    {
      if (m_wait_pong == true)
	throw std::logic_error("timeout");
      m_wait_pong = true;
      m_itcp_protocol.send_ping();
      return;
    }
  m_last->set_second(second);
  m_last->set_nano(nano);
}

void	Client::result(ITCP_protocol &, ITCP_protocol::Error)
{
}

void	Client::connect(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &password)
{
  if (m_server.check_login(login, password))
    {
      m_login = login;
      m_password = password;
    }
  else
    m_itcp_protocol.send_result(ITCP_protocol::WRONGLOGIN);
}

void	Client::disconnect(ITCP_protocol &itcp_protocol)
{
  m_login.clear();
  m_password.clear();
  throw std::logic_error("disconnect");
}

void	Client::ping(ITCP_protocol &itcp_protocol)
{
  itcp_protocol.send_pong();
}

void	Client::pong(ITCP_protocol &itcp_protocol)
{
  m_wait_pong = false;
}

void	Client::list_meta_games(ITCP_protocol &itcp_protocol)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::meta_games(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Game *> const &)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::create_game(ITCP_protocol &itcp_protocol, ITCP_protocol::Game const &game)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
  else
    {
      
    }
}

void	Client::join_game(ITCP_protocol &itcp_protocol, ITCP_protocol::Game const &game)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::message(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &message)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::list_meta_params(ITCP_protocol &itcp_protocol)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::meta_params(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Param *> const &)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::change_param(ITCP_protocol &itcp_protocol, ITCP_protocol::Param const &param)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::list_meta_sprites(ITCP_protocol &itcp_protocol)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::meta_sprites(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Sprite *> const &)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::take_sprite(ITCP_protocol &itcp_protocol, ITCP_protocol::Sprite const &sprite)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::give_sprite(ITCP_protocol &itcp_protocol, ITCP_protocol::Sprite const &sprite)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::list_meta_sounds(ITCP_protocol &itcp_protocol)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::meta_sounds(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Sound *> const &sounds)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::take_sound(ITCP_protocol &itcp_protocol, ITCP_protocol::Sound const &sound)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::give_sound(ITCP_protocol &itcp_protocol, ITCP_protocol::Sound const &sound)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::ready(ITCP_protocol &itcp_protocol, bool ready)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
  m_ready = ready;
}

void	Client::start(ITCP_protocol &itcp_protocol, uint8_t, uint16_t)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::end(ITCP_protocol &itcp_protocol, uint64_t, bool)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::leave(ITCP_protocol &itcp_protocol)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

std::string const	&Client::get_login(void) const
{
  return (m_login);
}

bool	Client::get_ready(void) const
{
  return (m_ready);
}
