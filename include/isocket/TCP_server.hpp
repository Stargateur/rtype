//
// TCP_server.hpp for TCP_server in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:16:07 2015 Antoine Plaskowski
// Last update Fri Nov 20 05:17:17 2015 Antoine Plaskowski
//

#ifndef		TCP_SERVER_HPP_
# define	TCP_SERVER_HPP_

# include	"ITCP_server.hpp"

class TCP_server : public ITCP_server
{
  TCP_server(std::string const &port);
  ITCP_client	accept(void) const;
};

#endif		/* !TCP_SERVER_HPP_ */
