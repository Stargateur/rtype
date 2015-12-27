//
// BasicGame.cpp for BasicGame in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 10:14:54 2015 Alaric Degand
// Last update Sun Dec 27 20:13:36 2015 Antoine Plaskowski
//

#include	<array>
#include	"BasicGame.hpp"
#include	"UDP_protocol.hpp"
#include	"Time.hpp"
#include	"Player.hpp"
#include	"Select.hpp"

BasicGame::BasicGame(std::string const &owner, Usine<fct_new_ientite> const &usine, std::string const &name, PortGenerator &port_generator) :
  m_name(name),
  m_all_ientites(usine.get_all(static_cast<uintmax_t>(2), static_cast<uintmax_t>(1920), static_cast<uintmax_t>(1080))),
  m_background(m_all_ientites.size(), 0, 1920, 1080),
  m_port(port_generator),
  m_iselect(*new Select()),
  m_iudp_server(*new UDP_server(m_port.get_str_port())),
  m_generator(reinterpret_cast<uintptr_t>(&m_iselect)),
  m_usine(usine)
{
  static const File	sprite("sprites/r-typesheet42.gif");
  m_params["size_x"] = "1920";
  m_params["size_y"] = "1080";
  m_params["max player"] = "4";
  m_logins.push_back(owner);
  m_all_players.push_back(new Player(sprite, sprite, "", m_all_ientites.size() + 1, 1, 0, 0, 10, 10, 1920, 1080));
}

BasicGame::~BasicGame(void)
{
  delete &m_iselect;
  delete &m_iudp_server;
}

void	BasicGame::run(void)
{
  ITime	&last_spawn = *new Time();
  ITime	&spawn = *new Time();
  ITime	&itime = *new Time();
  ITime	&now = *new Time();
  ITime	&wait = *new Time();
  ITime	&want_wait = *new Time();
  IUDP_protocol &iudp_protocol = *new UDP_protocol(*this);
  uintmax_t	i = 0;

  for (auto it = m_logins.begin(); it != m_logins.end(); it++)
    {
      m_players.push_back(m_all_players[i++ % m_all_players.size()]);
      m_ientites.push_back(m_players.back());
    }
  spawn.set_second(1);
  spawn.set_nano(0);
  last_spawn.set_second(0);
  last_spawn.set_nano(0);
  itime.now();
  while (m_players.size() != 0)
    {
      now.now();
      itime -= now;
      wait.set_second(1);
      std::list<IEntite *>	to_add;
      last_spawn += itime;
      for (auto it = m_ientites.begin(); it != m_ientites.end();)
	{
	  try
	    {
	      (*it)->run(m_ientites, to_add, itime, want_wait);
	      if (want_wait < wait)
		wait = want_wait;
	      it++;
	    }
	  catch (...)
	    {
	      m_players.remove(static_cast<Player *>(*it));
	      delete *it;
	      it = m_ientites.erase(it);
	    }
	}
      m_ientites.splice(m_ientites.end(), to_add);
      while (last_spawn >= spawn)
	{
	  i = m_distribution(m_generator) % m_all_ientites.size();
	  m_ientites.push_back(&m_usine.get<IEntite>(i, m_ientites, i, static_cast<uintmax_t>(2), static_cast<uintmax_t>(1920), static_cast<uintmax_t>(1080)));
	  last_spawn -= spawn;
	}
      m_iselect.reset();
      if (iudp_protocol.want_recvfrom() == true)
	m_iselect.want_read(m_iudp_server);
      if (iudp_protocol.want_sendto() == true)
	m_iselect.want_write(m_iudp_server);
      m_iselect.select(&wait);
      if (m_iselect.can_read(m_iudp_server) == true)
	iudp_protocol.recvfrom(m_iudp_server);
      if (m_iselect.can_write(m_iudp_server) == true)
	iudp_protocol.sendto(m_iudp_server);
      itime.now();
    }
  for (auto ientite : m_ientites)
    delete ientite;
  delete &itime;
  delete &spawn;
  delete &last_spawn;
  delete &now;
  delete &wait;
  delete &want_wait;
}

std::string const	&BasicGame::get_owner(void) const
{
  return (m_name);
}

std::list<std::string> const	&BasicGame::get_logins(void) const
{
  return (m_logins);
}

std::vector<Player *> const	&BasicGame::get_players(void) const
{
  return (m_all_players);
}
std::vector<IEntite *> const	&BasicGame::get_ientites(void) const
{
  return (m_all_ientites);
}

Background const	&BasicGame::get_background(void) const
{
  return (m_background);
}

void	BasicGame::set_name(std::string const &name)
{
  m_name = name;
}

std::string const	&BasicGame::get_name(void) const
{
  return (m_name);
}

void	BasicGame::add_login(std::string const &login)
{
  if (m_logins.size() < std::stoull(m_params["max player"]))
    m_logins.push_back(login);
}

void	BasicGame::sup_login(std::string const &login)
{
  m_logins.remove(login);
}

std::map<std::string, std::string> const	&BasicGame::get_meta_params(void) const
{
  return (m_params);
}

void	BasicGame::set_param(std::string const &name, std::string const &value)
{
  m_params.at(name) = value;
}

void	BasicGame::sprites(IUDP_protocol &, std::list<IUDP_protocol::Sprite *> const &)
{
  
}

void	BasicGame::sounds(IUDP_protocol &, std::list<IUDP_protocol::Sound *> const &)
{
}

void	BasicGame::input(IUDP_protocol &, std::string const &, IUDP_protocol::Input const &)
{
}

void	BasicGame::sprites(IUDP_protocol &, std::list<IUDP_protocol::Sprite *> const &, IUDP_server::u_sockaddr const &, socklen_t)
{
}

void	BasicGame::sounds(IUDP_protocol &, std::list<IUDP_protocol::Sound *> const &, IUDP_server::u_sockaddr const &, socklen_t)
{
}

void	BasicGame::input(IUDP_protocol &iudp_protocol, std::string const &login, IUDP_protocol::Input const &input, IUDP_server::u_sockaddr const &sockaddr, socklen_t len)
{
  for (auto player : m_players)
    {
      if (player->get_login() == login)
	{
	  player->set_input(input);
	  std::list<IUDP_protocol::Sprite *>	sprites;
	  sprites.push_back(new IUDP_protocol::Sprite({m_background.get_id(), m_background.get_x(), m_background.get_y(), 0}));
	  for (auto entite : m_ientites)
	    sprites.push_back(new IUDP_protocol::Sprite({entite->get_id(), entite->get_x(), entite->get_y(), 0}));
	  iudp_protocol.send_sprites(sprites, sockaddr, len);
	  for (auto sprite : sprites)
	    delete sprite;
	  return;
	}
    }
}

int16_t	BasicGame::get_port(void) const
{
  return (m_port.get_port());
}
