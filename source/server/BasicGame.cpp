//
// BasicGame.cpp for BasicGame in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 10:14:54 2015 Alaric Degand
// Last update Fri Dec 25 19:32:00 2015 Antoine Plaskowski
//

#include	<array>
#include	"BasicGame.hpp"
#include	"UDP_protocol.hpp"
#include	"Time.hpp"
#include	"Player.hpp"
#include	"Select.hpp"

BasicGame::BasicGame(std::string const &owner, Usine<fct_new_ientite> &usine, std::string const &name, PortGenerator &port_generator) :
  m_owner(owner),
  m_name(name),
  m_player_max(4),
  m_x(1920),
  m_y(1080),
  m_usine(usine),
  m_port(port_generator),
  m_iselect(*new Select()),
  m_iudp_server(*new UDP_server(m_port.get_port()))
{
}

BasicGame::~BasicGame(void)
{
  delete &m_iselect;
  delete &m_iudp_server;
}

void	BasicGame::run(void)
{
  static const File	sprite("sprites/r-typesheet42.gif");
  ITime	&itime = *new Time();
  ITime	&now = *new Time();
  ITime	&wait = *new Time();
  ITime	&want_wait = *new Time();
  IUDP_protocol &iudp_protocol = *new UDP_protocol(*this);

  m_players.push_back(new Player(sprite, sprite, m_owner, 1, 0, 0, 10, 10));
  for (auto it = m_login.begin(); it != m_login.end(); it++)
    {
      m_players.push_back(new Player(sprite, sprite, *it, 1, 0, 0, 10, 10));
      m_ientites.push_back(m_players.back());
    }
  itime.now();
  while (m_players.size() != 0)
    {
      now.now();
      itime.sub(now);
      wait.set_second(1);
      std::list<IEntite *>	to_add;
      for (auto it = m_ientites.begin(); it != m_ientites.end();)
	{
	  try
	    {
	      (*it)->run(m_ientites, to_add, itime, want_wait);
	      // compare wait et want_wait
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
      if (iudp_protocol.want_send() == true)
	m_iselect.want_read(m_iudp_server);
      if (iudp_protocol.want_recv() == true)
	m_iselect.want_write(m_iudp_server);
      m_iselect.select(&wait);
      //      if (m_iselect.can_read(
    }
  for (auto ientite : m_ientites)
    delete ientite;
  delete &itime;
  delete &now;
  delete &wait;
  delete &want_wait;
}

std::string const	&BasicGame::get_owner(void) const
{
  return (m_owner);
}

void	BasicGame::set_name(std::string const &name)
{
  m_name = name;
}

std::string const	&BasicGame::get_name(void) const
{
  return (m_name);
}

void	BasicGame::add_player(std::string const &login)
{
  m_login.push_back(login);
}

void	BasicGame::sup_player(std::string const &login)
{
  m_login.remove(login);
}

std::list<std::string> const  &BasicGame::get_player(void) const
{
  return (m_login);
}

std::map<std::string, std::string> const	&BasicGame::get_meta_params(void) const
{
  return (m_params);
}

void	BasicGame::set_param(std::string const &name, std::string const &value)
{
  m_params.at(name) = value;
}
