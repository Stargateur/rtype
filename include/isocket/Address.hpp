//
// Address.hpp for Address in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 04:58:06 2015 Antoine Plaskowski
// Last update Fri Nov 20 13:00:01 2015 Antoine Plaskowski
//

#ifndef		UDP_CLIENT_HPP_
# define	UDP_CLIENT_HPP_

# include	<arpa/inet.h>
# include	<sys/socket.h>
# include	"IAddress.hpp"

class	Address : public IAddress
{
public:
  Address(std::string const &host);
  std::string const	&get_host(void) const;
private:
  std::string const	m_host;
  union
  {
    struct sockaddr	base;
    struct sockaddr_in	ipv4;
    struct sockaddr_in6	ipv6;
  } const	m_sockaddr;
  socklen_t const	len;
};

#endif		/* !UDP_CLIENT_HPP_ */
