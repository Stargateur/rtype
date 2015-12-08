//
// TCP_client.cpp for TCP_client in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 06:49:55 2015 Antoine Plaskowski
// Last update Tue Dec  8 16:09:24 2015 Antoine Plaskowski
//

#include	<unistd.h>
#include	<iostream>
#include	<cstring>
#include	<utility>
#include	<arpa/inet.h>
#include	"TCP_client.hpp"

TCP_client::TCP_client(std::string const &host, std::string const &port) :
  ASocket(connect(host, port))
{
}

TCP_client::TCP_client(ITCP_server const &server) :
  ASocket(accept(server))
{
}

TCP_client::~TCP_client(void)
{
  close(m_fd);
}

int	TCP_client::accept(ITCP_server const &server)
{
  int fd = ::accept(server.get_fd(), NULL, NULL);
  if (fd == -1)
    throw TCP_client_exception(strerror(errno));

  return (fd);
}

int	TCP_client::aux_connect(struct addrinfo const *rp)
{
  int   fd;

  if (rp == NULL)
    throw TCP_client_exception(strerror(errno));
  if ((fd = ::socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    return (aux_connect(rp->ai_next));
  if (::connect(fd, rp->ai_addr, rp->ai_addrlen) != 0)
    {
      ::close(fd);
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
    throw TCP_client_exception(gai_strerror(status));

  int fd = aux_connect(result);
  ::freeaddrinfo(result);
  return (fd);
}

uintmax_t	TCP_client::recv(uint8_t &data, uintmax_t size) const
{
  ssize_t	ret = ::recv(m_fd, &data, size, 0);
  if (ret == -1)
    throw TCP_client_exception(strerror(errno));
  return (static_cast<uintmax_t>(ret));
}

uintmax_t	TCP_client::send(uint8_t const &data, uintmax_t size) const
{
  ssize_t	ret = ::send(m_fd, &data, size, 0);
  if (ret == -1)
    throw TCP_client_exception(strerror(errno));
  return (static_cast<uintmax_t>(ret));
}

TCP_client_exception::TCP_client_exception(char const *what) :
  m_what(what)
{
}

char const	*TCP_client_exception::what(void) const noexcept
{
  return (m_what);
}
