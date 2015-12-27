//
// Server.cpp for Server in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:15:49 2015 Alaric Degand
// Last update Sun Dec 27 15:29:18 2015 Antoine Plaskowski
//

#include	<iostream>
#include	"Client.hpp"
#include	"Server.hpp"
#include	"ASocket.hpp"
#include	"bind.hpp"

Server::Server(Option const &option) :
  m_itcp_server(*new TCP_server(option.get_opt("port"))),
  m_istandard(*new Standard(IStandard::In)),
  m_iselect(*new Select()),
  m_usine(option.get_zero().substr(0, option.get_zero().find_last_of("\\/")), NAME_FCT_NEW_IENTITE),
  m_timeout(*new Time()),
  m_port_generator(std::stoll(option.get_opt("udp_min")), std::stoll(option.get_opt("udp_max"))),
  m_pool(5)
{
  m_timeout.set_second(5);
  m_timeout.set_nano(0);
}

Server::~Server(void)
{
  delete &m_iselect;
  delete &m_istandard;
  delete &m_itcp_server;
  delete &m_timeout;
}

void		Server::run(void)
{
  bool	g_keep_running = true;

  while (g_keep_running == true)
    {
      m_iselect.want_read(m_istandard);
      m_iselect.want_read(m_itcp_server);
      for (auto client : m_clients)
	client->pre_run(m_iselect);
      m_iselect.select();
      if (m_iselect.can_read(m_itcp_server))
	m_clients.push_back(new Client(*this, m_itcp_server.accept()));
      if (m_iselect.can_read(m_istandard))
	{
	  uint8_t	buffer[42];

	  if (m_istandard.read(buffer[0], 42) == 0)
	    g_keep_running = false;
	}
      for (auto it = m_clients.begin(); it != m_clients.end();)
	{
	  try
	    {
	      (*it)->run(m_iselect, m_timeout);
	      it++;
	    }
	  catch (std::exception const &e)
	    {
	      leave_game((*it)->get_login());
	      std::cerr << e.what() << std::endl;
	      it = m_clients.erase(it);
	    }
	}
    }
}

bool		Server::check_login(std::string const &login, std::string const &passwd) const
{
  if (login != passwd)
    return (false);
  for (auto client : m_clients)
    if (login == client->get_login())
      return (false);
  return (true);
}

IGame const	&Server::get_game(std::string const &login) const
{
  for (auto game : m_games)
    for (auto login2 : game->get_logins())
      if (login2 == login)
	return (*game);
  throw std::logic_error("no game");
}

std::list<IGame *> const	&Server::get_games(void) const
{
  return (m_games);
}

void	Server::create_game(std::string const &login)
{
  m_games.push_back(new BasicGame(login, m_usine, login, m_port_generator));
}

void	Server::join_game(std::string const &login, std::string const &owner)
{
  for (auto game : m_games)
    if (game->get_owner() == owner)
      game->add_login(login);
  throw std::logic_error("no game");
}

void	Server::leave_game(std::string const &login)
{
  for (auto game : m_games)
    for (auto login2 : game->get_logins())
      if (login2 == login)
	game->sup_login(login);
}

static int	lol(int id, IGame *game)
{
  game->run();
  delete game;
  return (id);
}

void	Server::start_game(std::string const &login)
{
  for (auto game : m_games)
    for (auto login2 : game->get_logins())
      if (login2 == login)
	{
	  m_games.remove(game);
	  m_pool.start(bind(&lol, _1, game));
	}
}
