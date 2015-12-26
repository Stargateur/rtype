//
// Client.cpp for Client in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:56:02 2015 Alaric Degand
// Last update Sat Dec 26 15:29:15 2015 Antoine Plaskowski
//

#include	"Client.hpp"

Client::Client(Server &server, ITCP_client &itcp_client) :
  m_server(server),
  m_itcp_client(itcp_client),
  m_itcp_protocol(*new TCP_protocol(*this))
{
}

Client::~Client(void)
{
  delete &m_itcp_client;
  delete &m_itcp_protocol;
}

void	Client::result(ITCP_protocol &itcp_protocol, ITCP_protocol::Error error)
{
}

void	Client::connect(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &password)
{
  if (m_server.check_login(login, password))
    {
      m_login = login;
      m_password = password;
      m_itcp_protocol.send_result(ITCP_protocol::NONE);
    }
  else
    m_itcp_protocol.send_result(ITCP_protocol::CONNECT);
}

void	Client::disconnect(ITCP_protocol &itcp_protocol)
{
  m_login.clear();
  m_password.clear();
}

void	Client::ping(ITCP_protocol &itcp_protocol)
{
  m_itcp_protocol.send_pong();
}

void	Client::pong(ITCP_protocol &itcp_protocol)
{
}

void	Client::list_meta_games(ITCP_protocol &itcp_protocol)
{
  if (m_login == "")
      m_itcp_protocol.send_result(ITCP_protocol::IGNORED);
  else
    m_itcp_protocol.send_list_meta_games();
}

void	Client::meta_games(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Game *> const &games)
{
}

void	Client::create_game(ITCP_protocol &itcp_protocol, ITCP_protocol::Game const &game)
{
  
}

void	Client::join_game(ITCP_protocol &itcp_protocol, ITCP_protocol::Game const &game)
{
}

void	Client::message(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &message)
{
  Client	*target_client;
  
  if (m_login == "")
    m_itcp_protocol.send_result(ITCP_protocol::IGNORED);
  else
    {
      target_client = m_server.get_client(login);
      if (target_client != NULL)
	target_client->m_itcp_protocol.send_message(login, message);
      else
	m_itcp_protocol.send_result(ITCP_protocol::WRONGLOGIN);
    }
}

// void	Client::list_modes(ITCP_protocol &itcp_protocol)
// {
// }

// void	Client::meta_modes(ITCP_protocol &itcp_protocol, std::list<Mode *> const &modes)

// void	Client::change_mode(ITCP_protocol &itcp_protocol, std::string const &mode)
// {
// }

void	Client::list_meta_params(ITCP_protocol &itcp_protocol)
{
}

void	Client::meta_params(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Param *> const &params)
{
}

void	Client::change_param(ITCP_protocol &itcp_protocol, ITCP_protocol::Param const &param)
{
}

void	Client::list_meta_sprites(ITCP_protocol &itcp_protocol)
{
}

void	Client::meta_sprites(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Sprite *> const &sprites)
{
}

void	Client::take_sprite(ITCP_protocol &itcp_protocol, ITCP_protocol::Sprite const &sprite)
{
}

void	Client::give_sprite(ITCP_protocol &itcp_protocol, ITCP_protocol::Sprite const &sprite)
{
}

void	Client::list_meta_sounds(ITCP_protocol &itcp_protocol)
{
}

void	Client::meta_sounds(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Sound *> const &sounds)
{
}

void	Client::take_sound(ITCP_protocol &itcp_protocol, ITCP_protocol::Sound const &sound)
{
}

void	Client::give_sound(ITCP_protocol &itcp_protocol, ITCP_protocol::Sound const &sound)
{
}

void	Client::ready(ITCP_protocol &itcp_protocol, bool ready)
{
}

void	Client::start(ITCP_protocol &itcp_protocol, uint8_t second, uint16_t port)
{
}

void	Client::end(ITCP_protocol &itcp_protocol, uint64_t score, bool winner)
{
}

void	Client::leave(ITCP_protocol &itcp_protocol)
{
}

std::string	Client::get_login() const
{
  return (m_login);
}
