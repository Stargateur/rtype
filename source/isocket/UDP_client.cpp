//
// UDP_client.cpp for UDP_client in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 12:09:50 2015 Antoine Plaskowski
// Last update Tue Dec  8 16:07:48 2015 Antoine Plaskowski
//

#include	<sys/socket.h>
#include	<netdb.h>
#include	<cstring>
#include	<unistd.h>
#include	<iostream>
#include	"UDP_client.hpp"

UDP_client::UDP_client(std::string const &host, std::string const &port) :
  ASocket(connect(host, port))
{
}

uintmax_t	UDP_client::send(uint8_t const &data, uintmax_t size) const
{
  ssize_t	ret = ::send(m_fd, &data, size, 0);
  if (ret == -1)
    throw UDP_client_exception(strerror(errno));
  return (static_cast<uintmax_t>(ret));
}

uintmax_t	UDP_client::recv(uint8_t &data, uintmax_t size) const
{
  ssize_t	ret = ::recv(m_fd, &data, size, 0);
  if (ret == -1)
    throw UDP_client_exception(strerror(errno));
  return (static_cast<uintmax_t>(ret));
}

int     UDP_client::aux_connect(struct addrinfo const *rp)
{
  int   fd;

  if (rp == NULL)
    throw UDP_client_exception(strerror(errno));
  if ((fd = ::socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    return (aux_connect(rp->ai_next));
  if (::connect(fd, rp->ai_addr, rp->ai_addrlen) == -1)
    {
      ::close(fd);
      return (aux_connect(rp->ai_next));
    }
  return (fd);
}

int     UDP_client::connect(std::string const &host, std::string const &port)
{
  struct addrinfo const hints =
    {
      0,
      AF_UNSPEC,
      SOCK_DGRAM,
      IPPROTO_UDP,
      0,
      NULL,
      NULL,
      NULL    };
  struct addrinfo       *result;
  int   status = ::getaddrinfo(host.c_str(), port.c_str(), &hints, &result);
  if (status != 0)
    throw UDP_client_exception(gai_strerror(status));

  int fd = aux_connect(result);
  ::freeaddrinfo(result);
  return (fd);
}

UDP_client_exception::UDP_client_exception(char const *what) :
  m_what(what)
{
}

char const	*UDP_client_exception::what(void) const noexcept
{
  return (m_what);
}
