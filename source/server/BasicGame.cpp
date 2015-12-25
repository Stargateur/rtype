//
// BasicGame.cpp for BasicGame in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 10:14:54 2015 Alaric Degand
// Last update Fri Dec 25 17:38:56 2015 Antoine Plaskowski
//

#include	<array>
#include	"BasicGame.hpp"
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
  std::list<Player *>	players;
  std::list<IEntite *>	ientites;

  players.push_back(new Player(sprite, sprite, m_owner, 1, 0, 0, 10, 10));
  for (auto it = m_player.begin(); it != m_player.end(); it++)
    {
      players.push_back(new Player(sprite, sprite, *it, 1, 0, 0, 10, 10));
      ientites.push_back(players.back());
    }
  itime.now();
  while (players.size() != 0)
    {
      now.now();
      itime.sub(now);
      wait.set_second(1);
      std::list<IEntite *>	to_add;
      for (auto it = ientites.begin(); it != ientites.end();)
	{
	  try
	    {
	      (*it)->run(ientites, to_add, itime, want_wait);
	      // compare wait et want_wait
	      it++;
	    }
	  catch (...)
	    {
	      players.remove(static_cast<Player *>(*it));
	      delete *it;
	      it = ientites.erase(it);
	    }
	}
      ientites.splice(ientites.end(), to_add);
      m_iselect.want_read(m_iudp_server);
      m_iselect.select(&wait);
    }
  for (auto ientite : ientites)
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

std::map<std::string, std::string> const	&BasicGame::get_meta_params(void) const
{
  return (m_params);
}

void	BasicGame::set_param(std::string const &name, std::string const &value)
{
  m_params.at(name) = value;
}
