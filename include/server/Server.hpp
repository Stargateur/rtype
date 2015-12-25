//
// Server.hpp for Server in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:05:56 2015 Alaric Degand
// Last update Fri Dec 25 12:28:42 2015 Antoine Plaskowski
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
  Client	*get_client(std::string const &login) const;
private:
  ITCP_server const	&m_itcp_server;
  IStandard	&m_istandard;
  std::list<Client *>	m_clients;
  std::list<IGame *>	m_games;
  ISelect	&m_iselect;
  Usine<fct_new_ientite>	m_usine;
};

#endif		/* !SERVER_HPP_ */
