//
// Server.hpp for Server in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:05:56 2015 Alaric Degand
// Last update Sun Dec 27 07:03:30 2015 Antoine Plaskowski
//

#ifndef		SERVER_HPP_
# define	SERVER_HPP_

#include	<list>
#include	<string>

class		Server;

#include	"Client.hpp"
#include	"Option.hpp"
#include	"TCP_server.hpp"
#include	"Standard.hpp"
#include	"BasicGame.hpp"
#include	"Usine.hpp"
#include	"Select.hpp"

class	Server
{
public:
  Server(Option const &option);
  ~Server(void);
  void	run(void);
  bool	check_login(std::string const &login, std::string const &password) const;
  void	send_message(std::string const &login, std::string const &message) const;
  void	create_game(std::string const &login);
  void	join_game(std::string const &login, std::string const &owner);
  std::list<IGame *> const	&get_games(void) const;
  IGame const	&get_game(void) const;
  IGame	&get_game(void);
private:
  ITCP_server const	&m_itcp_server;
  IStandard	&m_istandard;
  std::list<Client *>	m_clients;
  std::list<IGame *>	m_games;
  ISelect	&m_iselect;
  Usine<fct_new_ientite>	m_usine;
  ITime	&m_timeout;
};

#endif		/* !SERVER_HPP_ */
