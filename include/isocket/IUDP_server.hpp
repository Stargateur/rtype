//
// IUDP_server.hpp for IUDP_server in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:00:20 2015 Antoine Plaskowski
// Last update Tue Dec  8 15:35:32 2015 Antoine Plaskowski
//

#ifndef		IUDP_SERVER_HPP_
# define	IUDP_SERVER_HPP_

# include	<cstdint>
# include	<string>
# include	"ASocket.hpp"

class	IUDP_server;

# include	"IUDP_client.hpp"

class	IUDP_server : virtual public ISocket
{
public:
  union u_sockaddr
  {
    struct sockaddr     base;
    struct sockaddr_in  ipv4;
    struct sockaddr_in6 ipv6;
  };
public:
  virtual	~IUDP_server(void);
  virtual uintmax_t	recvfrom(uint8_t &data, uintmax_t size, u_sockaddr &sockaddr, socklen_t &len) const = 0;
  virtual uintmax_t	sendto(uint8_t const &data, uintmax_t size, u_sockaddr const &sockaddr, socklen_t const len) const = 0;
};

class	IUDP_server_exception : public ISocket_exception
{
public:
  virtual ~IUDP_server_exception(void);
};

#endif		/* !IUDP_SERVER_HPP_ */
