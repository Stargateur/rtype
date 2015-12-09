//
// Server.hpp for Server in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:05:56 2015 Alaric Degand
// Last update Wed Dec  9 15:58:47 2015 Antoine Plaskowski
//

#ifndef		SERVER_HPP_
# define	SERVER_HPP_

#include	<list>
#include	<string>

class		Server;

#include	"Client.hpp"
#include	"TCP_server.hpp"
//#include	"Game.hpp"
#include	"Select.hpp"

class		Server
{
private:
  ITCP_server const	&m_itcp_server;
  std::list<Client *>	m_clients;
  //  std::list<Game *>	m_games;
  ISelect	&m_iselect;
public:
  Server(std::string const &port);
  void		run(void);
};

#endif		/* !SERVER_HPP_ */
