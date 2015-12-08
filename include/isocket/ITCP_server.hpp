//
// ITCP_server.hpp for ITCP_server in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:13:59 2015 Antoine Plaskowski
// Last update Tue Dec  8 15:01:04 2015 Antoine Plaskowski
//

#ifndef		ITCP_SERVER_HPP_
# define	ITCP_SERVER_HPP_

# include	"ASocket.hpp"
# include	"ITCP_client.hpp"

class	ITCP_server : virtual public ISocket
{
public:
  virtual ~ITCP_server(void);
  virtual ITCP_client	&accept(void) const = 0;
};

class	ITCP_server_exception : public ISocket_exception
{
  virtual ~ITCP_server_exception(void);
};

#endif		/* !ITCP_SERVER_HPP_ */
