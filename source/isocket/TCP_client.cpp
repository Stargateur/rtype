//
// TCP_client.cpp for TCP_client in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 06:49:55 2015 Antoine Plaskowski
// Last update Fri Nov 20 07:49:51 2015 Antoine Plaskowski
//

#include	<unistd.h>
#include	<iostream>
#include	<cstring>
#include	<arpa/inet.h>
#include	"TCP_client.hpp"

TCP_client::TCP_client(std::string const &host, std::string const &port) :
  ITCP_client(connect(host, port)),
  m_host(host)
{
}

TCP_client::TCP_client(ITCP_server const &server) :
  ITCP_client(accept(server, m_host))
{
}

TCP_client::~TCP_client(void)
{
  close(m_fd);
}

int	TCP_client::accept(ITCP_server const &server, std::string &host)
{
  union
  {
    struct sockaddr	base;
    struct sockaddr_in	ipv4;
    struct sockaddr_in6	ipv6;
  }	sockaddr;
  socklen_t	len = sizeof(sockaddr);
  std::memset(&sockaddr.base, 0, len);
  int	fd = ::accept(server.get_fd(), &sockaddr.base, &len);
  if (fd == -1)
    {
      perror("accept()");
      throw std::exception();
    }

  switch (sockaddr.base.sa_family)
    {
    case AF_INET:
      char      ipv4[INET_ADDRSTRLEN];
      if (inet_ntop(AF_INET, &sockaddr.ipv4.sin_addr, ipv4, sizeof(ipv4)) == NULL)
	perror("inet_ntop()");
      else
	host = ipv4;
      return (fd);
    case AF_INET6:
      char      ipv6[INET6_ADDRSTRLEN];
      if (inet_ntop(AF_INET6, &sockaddr.ipv6.sin6_addr, ipv6, sizeof(ipv6)) == NULL)
	perror("inet_ntop()");
      else
	host = ipv6;
      return (fd);
    }
  return (fd);
}

int	TCP_client::aux_connect(struct addrinfo const *rp)
{
  int   fd;

  if (rp == NULL)
    throw std::exception();
  if ((fd = ::socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    {
      perror("socket()");
      return (aux_connect(rp->ai_next));
    }
  if (::connect(fd, rp->ai_addr, rp->ai_addrlen) != 0)
    {
      perror("connect()");
      if (::close(fd) == -1)
	perror("close()");
      return (aux_connect(rp->ai_next));
    }
  return (fd);
}

int	TCP_client::connect(std::string const &host, std::string const &port)
{
  struct addrinfo const	hints =
    {
      0,
      AF_UNSPEC,
      SOCK_STREAM,
      IPPROTO_TCP,
      0,
      NULL,
      NULL,
      NULL
    };
  struct addrinfo	*result;
  int   status = ::getaddrinfo(host.c_str(), port.c_str(), &hints, &result);
  if (status != 0)
    {
      std::cerr << "getaddrinfo: " << gai_strerror(status) <<  std::endl;
      throw std::exception();
    }

  int fd = aux_connect(result);
  ::freeaddrinfo(result);
  return (fd);
}

uintmax_t	TCP_client::recv(uint8_t &data, uintmax_t size) const
{
  ssize_t	ret = ::recv(m_fd, &data, size, 0);
  if (ret == -1)
    throw std::exception();
  return (static_cast<uintmax_t>(ret));
}

uintmax_t	TCP_client::send(uint8_t const &data, uintmax_t size) const
{
  ssize_t	ret = ::send(m_fd, &data, size, 0);
  if (ret == -1)
    throw std::exception();
  return (static_cast<uintmax_t>(ret));
}

std::string const	&TCP_client::get_host(void) const
{
  return (m_host);
}
