//
// IUDP_server.hpp for IUDP_server in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:00:20 2015 Antoine Plaskowski
// Last update Mon Dec  7 17:07:18 2015 Antoine Plaskowski
//

#ifndef		IUDP_SERVER_HPP_
# define	IUDP_SERVER_HPP_

# include	<cstdint>
# include	<string>
# include	"ASocket.hpp"
# include	"IUDP_client.hpp"

class	IUDP_server : virtual public ISocket
{
public:
  virtual	~IUDP_server(void);
  virtual uintmax_t	recvfrom(uint8_t &data, uintmax_t &size, IUDP_client &client) const = 0;
};

#endif		/* !IUDP_SERVER_HPP_ */
