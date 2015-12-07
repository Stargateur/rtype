//
// IUDP_client.hpp for IUDP_client in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 04:52:54 2015 Antoine Plaskowski
// Last update Mon Dec  7 18:18:48 2015 Antoine Plaskowski
//

#ifndef		IUDP_CLIENT_HPP_
# define	IUDP_CLIENT_HPP_

# include	<string>
# include	<sys/socket.h>
# include	<arpa/inet.h>

class	IUDP_client;

# include	"IUDP_server.hpp"

class	IUDP_client
{
public:
  virtual	~IUDP_client(void);
  virtual std::string const	&get_host(void) const = 0;
  virtual uintmax_t	sendto(uint8_t const &data, uintmax_t size, IUDP_server const &server) const = 0;
};

#endif		/* !IUDP_CLIENT_HPP_ */
