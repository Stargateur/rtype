//
// Client.hpp for Client in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:53:39 2015 Alaric Degand
// Last update Sun Dec  6 04:07:26 2015 Alaric Degand
//

#ifndef		CLIENT_HPP_
# define	CLIENT_HPP_

#include	"ITCP_client.hpp"

class		Client
{
private:
  ITCP_client const	&m_itcp_client;
public:
  Client(ITCP_client &);
}

#endif		/* !CLIENT_HPP_ */
