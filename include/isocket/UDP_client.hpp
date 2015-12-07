//
// IUDP_client.hpp for IUDP_client in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 04:58:06 2015 Antoine Plaskowski
// Last update Mon Dec  7 16:58:33 2015 Antoine Plaskowski
//

#ifndef		UDP_CLIENT_HPP_
# define	UDP_CLIENT_HPP_

# include	<arpa/inet.h>
# include	<sys/socket.h>
# include	"IIUDP_client.hpp"

class	IUDP_client : public IIUDP_client
{
private:
  union	sockaddr
  {
    struct sockaddr	base;
    struct sockaddr_in	ipv4;
    struct sockaddr_in6	ipv6;
  };
public:
  IUDP_client(sockaddr sockaddr, socklen_t len);
  IUDP_client(std::string const &host);
  std::string const	&get_host(void) const;
  uintmax_t	recvto(uint8_t const &data, uintmax_t size) const;
public:
  std::string const	m_host;
  sockaddr const	m_sockaddr;
  socklen_t const	m_len;
};

#endif		/* !UDP_CLIENT_HPP_ */
