//
// TCP_server.hpp for TCP_server in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:16:07 2015 Antoine Plaskowski
// Last update Fri Nov 20 15:39:15 2015 Antoine Plaskowski
//

#ifndef		TCP_SERVER_HPP_
# define	TCP_SERVER_HPP_

# include	<string>
# include	<sys/socket.h>
# include	<netdb.h>
# include	"ITCP_server.hpp"

class TCP_server : public ASocket, public ITCP_server
{
public:
  TCP_server(std::string const &port);
  ~TCP_server(void);
  ITCP_client	&accept(void) const;
private:
  static int	aux_bind(struct addrinfo const *rp);
  static int	bind(std::string const &port);
};

#endif		/* !TCP_SERVER_HPP_ */
