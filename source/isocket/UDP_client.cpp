//
// UDP_client.cpp for UDP_client in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 12:09:50 2015 Antoine Plaskowski
// Last update Tue Dec  8 03:09:40 2015 Antoine Plaskowski
//

#include	<sys/socket.h>
#include	<netdb.h>
#include	<cstring>
#include	<unistd.h>
#include	<iostream>
#include	"UDP_client.hpp"

UDP_client::UDP_client(std::string const &host, std::string const &port) :
  ASocket(connect(host, port)),
  m_host(host)
{
}

std::string const	&UDP_client::get_host(void) const
{
  return (m_host);
}

uintmax_t	UDP_client::send(uint8_t const &data, uintmax_t size) const
{
  ssize_t	ret = ::send(m_fd, &data, size, 0);
  if (ret == -1)
    throw std::exception();
  return (static_cast<uintmax_t>(ret));
}

uintmax_t	UDP_client::recv(uint8_t &data, uintmax_t size) const
{
  ssize_t	ret = ::recv(m_fd, &data, size, 0);
  if (ret == -1)
    throw std::exception();
  return (static_cast<uintmax_t>(ret));
}

int     UDP_client::aux_connect(struct addrinfo const *rp)
{
  int   fd;

  if (rp == NULL)
    throw std::exception();
  if ((fd = ::socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1)
    {
      perror("socket()");
      return (aux_connect(rp->ai_next));
    }
  if (::connect(fd, rp->ai_addr, rp->ai_addrlen) == -1)
    {
      perror("connect()");
      if (::close(fd) == -1)
	perror("close()");
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
      {
	std::cerr << "getaddrinfo: " << gai_strerror(status) <<  std::endl;
	throw std::exception();
      }

    int fd = aux_connect(result);
    ::freeaddrinfo(result);
    return (fd);
}
