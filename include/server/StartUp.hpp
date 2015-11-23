//
// StartUp.hpp for StartUp in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 23 10:54:38 2015 Anthony Bury
// Last update Mon Nov 23 11:51:37 2015 Anthony Bury
//

#ifndef		STARTUP_HPP_
# define	STARTUP_HPP_

# include	<vector>

# include	"TCP_server.hpp"
# include	"TCP_client.hpp"

class StartUp
{
  ITCP_server *m_tcp;
  bool m_end;
  std::vector<ITCP_client *> m_lobbyClients;

public:
  StartUp(const std::string &);
  ~StartUp(void);

public:
  void loop(void);
  
};

#endif		/* !STARTUP_HPP_ */
