//
// UDP_client.cpp for UDP_client in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 12:09:50 2015 Antoine Plaskowski
// Last update Mon Dec  7 18:52:21 2015 Antoine Plaskowski
//

#include	"UDP_client.hpp"

UDP_client::UDP_client(u_sockaddr const &sockaddr, socklen_t len) :
  UDP_client(get_host_with_addr(sockaddr, len), sockaddr, len)
{
}

UDP_client::UDP_client(std::string const &host, u_sockaddr const &sockaddr, socklen_t len) :
  m_host(host),
  m_sockaddr(sockaddr),
  m_len(len)
{
  delete &host;
}
/*
UDP_client::UDP_client(std::string const &host, std::pair<u_sockaddr, socklen_t> const &addr_len) :
  m_host(host),
  m_sockaddr(addr_len.first),
  m_len(addr_len.second)
{
  delete &addr_len;
}

UDP_client::UDP_client(std::string const &host, std::string const &port) :
  UDP_client(host, get_addr_with_host_port(host, port))
{
}
*/
std::string const	&UDP_client::get_host(void) const
{
  return (m_host);
}

uintmax_t	UDP_client::sendto(uint8_t const &data, uintmax_t size, IUDP_server const &server) const
{
  ssize_t	ret = ::sendto(server.get_fd(), &data, size, 0, &m_sockaddr.base, m_len);
  if (ret == -1)
    throw std::exception();
  return (static_cast<uintmax_t>(ret));
}

std::string const	&UDP_client::get_host_with_addr(u_sockaddr const &sockaddr, socklen_t len)
{
  switch (sockaddr.base.sa_family)
    {
    case AF_INET:
      char      ipv4[INET_ADDRSTRLEN];
      if (inet_ntop(AF_INET, &sockaddr.ipv4.sin_addr, ipv4, sizeof(ipv4)) == NULL)
	perror("inet_ntop()");
      else
	return (*new std::string(ipv4));
      break;
    case AF_INET6:
      char      ipv6[INET6_ADDRSTRLEN];
      if (inet_ntop(AF_INET6, &sockaddr.ipv6.sin6_addr, ipv6, sizeof(ipv6)) == NULL)
	perror("inet_ntop()");
      else	
	return (*new std::string(ipv6));
      break;
    }
  return (*new std::string());
}
/*
int	UDP_server::aux_get_addr_with_host_port(struct addrinfo const *rp)
{
  int	fd;

  if (rp == NULL)
    throw std::exception();
  if ((fd = ::socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    {
      perror("socket()");
      return (aux_socket(rp->ai_next));
    }
  return (fd);
}

std::pair<u_sockaddr, socklen_t> const	&UDP_server::get_addr_with_host_port(std::string const &host, std::string const &port)
{
    struct addrinfo const	hints =
      {
	AI_PASSIVE,
	AF_UNSPEC,
	SOCK_DGRAM,
	IPPROTO_UDP,
	0,
	NULL,
	NULL,
	NULL    };
    struct addrinfo	*result;
    int	status = ::getaddrinfo(host., port.c_str(), &hints, &result);
    if (status != 0)
      {
	std::cerr << "getaddrinfo: " << gai_strerror(status) <<  std::endl;
	throw std::exception();
      }
    std::pair<u_sockaddr, socklen_t> const &ret(aux_socket(result);
    ::freeaddrinfo(result);
    return (  
}
*/
