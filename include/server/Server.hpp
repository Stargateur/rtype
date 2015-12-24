//
// Server.hpp for Server in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:05:56 2015 Alaric Degand
// Last update Thu Dec 24 09:06:35 2015 Antoine Plaskowski
//

#ifndef		SERVER_HPP_
# define	SERVER_HPP_

#include	<list>
#include	<string>

class		Server;

#include	"Client.hpp"
#include	"Option.hpp"
#include	"TCP_server.hpp"
#include	"BasicGame.hpp"
#include	"Usine.hpp"
#include	"Select.hpp"

class	Server
{
public:
  Server(Option const &option);
  void	run(void);
  bool	check_login(std::string const &login, std::string const &password);
private:
  ITCP_server const	&m_itcp_server;
  std::list<Client *>	m_clients;
  std::list<IGame *>	m_games;
  ISelect	&m_iselect;
  Usine<fct_new_ientite>	m_usine;
};

#endif		/* !SERVER_HPP_ */
