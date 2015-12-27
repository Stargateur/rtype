//
// Server.hpp for Server in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:05:56 2015 Alaric Degand
// Last update Sun Dec 27 12:33:36 2015 Antoine Plaskowski
//

#ifndef		SERVER_HPP_
# define	SERVER_HPP_

#include	<list>
#include	<string>

class		Server;

# include	"Client.hpp"
# include	"Option.hpp"
# include	"TCP_server.hpp"
# include	"Standard.hpp"
# include	"BasicGame.hpp"
# include	"Usine.hpp"
# include	"Select.hpp"
# include	"ThreadPool.hpp"

class	Server
{
public:
  Server(Option const &option);
  ~Server(void);
  void	run(void);
  bool	check_login(std::string const &login, std::string const &password) const;
  void	send_message(std::string const &login, std::string const &message) const;
  void	create_game(std::string const &owner);
  void	join_game(std::string const &login, std::string const &owner);
  void	leave_game(std::string const &login);
  std::list<IGame *> const	&get_games(void) const;
  IGame const	&get_game(std::string const &login) const;
  void	start_game(std::string const &login);
private:
  ITCP_server const	&m_itcp_server;
  IStandard	&m_istandard;
  std::list<Client *>	m_clients;
  std::list<IGame *>	m_games;
  std::list<IGame *>	m_games_run;
  ISelect	&m_iselect;
  Usine<fct_new_ientite>	m_usine;
  ITime	&m_timeout;
  PortGenerator	m_port_generator;
  ThreadPool	m_pool;
};

#endif		/* !SERVER_HPP_ */
