//
// UDP_server.cpp for UDP_server in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 07:53:57 2015 Antoine Plaskowski
// Last update Mon Nov 23 09:54:36 2015 Anthony Bury
//

#include	<unistd.h>
#include	<iostream>
#include	<cstring>
#include	<arpa/inet.h>
#include	"UDP_server.hpp"

UDP_server::UDP_server(std::string const &port) :
  ASocket(socket(port)),
  m_port(port)
{
}

UDP_server::~UDP_server(void)
{
  ::shutdown(m_fd, SHUT_RDWR);
}

int	UDP_server::aux_socket(struct addrinfo const *rp)
{
  int   fd;

  if (rp == NULL)
    throw std::exception();
  if ((fd = ::socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    {
      perror("socket()");
      return (aux_socket(rp->ai_next));
    }
  return (fd);
}

int	UDP_server::socket(std::string const &port)
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
      NULL
    };
  struct addrinfo	*result;
  int   status = ::getaddrinfo(NULL, port.c_str(), &hints, &result);
  if (status != 0)
    {
      std::cerr << "getaddrinfo: " << gai_strerror(status) <<  std::endl;
      throw std::exception();
    }

  int	fd = aux_socket(result);
  ::freeaddrinfo(result);
  return (fd);
}

uintmax_t	UDP_server::recvfrom(uint8_t &data, uintmax_t &size, std::string &client) const
{
  union
  {
    struct sockaddr     base;
    struct sockaddr_in  ipv4;
    struct sockaddr_in6 ipv6;
  }     sockaddr;
  socklen_t     len = sizeof(sockaddr);
  std::memset(&sockaddr.base, 0, len);
  ssize_t   ret = ::recvfrom(m_fd, &data, size, 0, &sockaddr.base, &len);
  if (ret == -1)
    {
      perror("recvfrom()");
      throw std::exception();
    }
  //essayé getnameinfo café ?
  switch (sockaddr.base.sa_family)
    {
    case AF_INET:
      char      ipv4[INET_ADDRSTRLEN];
      if (inet_ntop(AF_INET, &sockaddr.ipv4.sin_addr, ipv4, sizeof(ipv4)) == NULL)
	perror("inet_ntop()");
      else
	client = ipv4;
      return (static_cast<size_t>(ret));
    case AF_INET6:
      char      ipv6[INET6_ADDRSTRLEN];
      if (inet_ntop(AF_INET6, &sockaddr.ipv6.sin6_addr, ipv6, sizeof(ipv6)) == NULL)
	perror("inet_ntop()");
      else
	client = ipv6;
      return (static_cast<size_t>(ret));
    }
  return (static_cast<size_t>(ret));
}

uintmax_t	UDP_server::sendto(uint8_t const &data, uintmax_t &size, std::string const &client) const
{
}
