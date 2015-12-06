//
// Server.hpp for Server in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:05:56 2015 Alaric Degand
// Last update Sun Dec  6 03:34:23 2015 Alaric Degand
//

#ifndef		SERVER_HPP_
# define	SERVER_HPP_

#include	<list>
#include	<string>
#include	"Client.hpp"
//#include	"Game.hpp"

class		Server
{
private:
  ITCP_server const	&m_itcp_server;
  std::list<Client *>	m_clients;
  //  std::list<Game *>	m_games;
public:
  Server(std::string const &port);
  void		run(void);
};

#endif		/* !SERVER_HPP_ */
