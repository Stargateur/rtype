//
// IUDP_client.hpp for IUDP_client in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 04:58:06 2015 Antoine Plaskowski
// Last update Mon Dec  7 18:52:50 2015 Antoine Plaskowski
//

#ifndef		UDP_CLIENT_HPP_
# define	UDP_CLIENT_HPP_

# include	<arpa/inet.h>
# include	<sys/socket.h>
# include	"IUDP_client.hpp"

class	UDP_client : public IUDP_client
{
public:
  union	u_sockaddr
  {
    struct sockaddr	base;
    struct sockaddr_in	ipv4;
    struct sockaddr_in6	ipv6;
  };
public:
  UDP_client(u_sockaddr const &sockaddr, socklen_t len);
  // UDP_client(std::string const &host, std::string const &port);
  std::string const	&get_host(void) const;
  uintmax_t	sendto(uint8_t const &data, uintmax_t size, IUDP_server const &server) const;
private:
  UDP_client(std::string const &host, u_sockaddr const &sockaddr, socklen_t len);
  // UDP_client(std::string const &host, std::pair<u_sockaddr, socklen_t> const &addr_len);
  static std::string const	&get_host_with_addr(u_sockaddr const &sockaddr, socklen_t len);
public:
  std::string const	m_host;
  u_sockaddr const	m_sockaddr;
  socklen_t const	m_len;
};

#endif		/* !UDP_CLIENT_HPP_ */
