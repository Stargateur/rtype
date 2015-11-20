//
// TCP_server.cpp for TCP_server in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 07:15:53 2015 Antoine Plaskowski
// Last update Fri Nov 20 15:40:14 2015 Antoine Plaskowski
//

#include	<iostream>
#include	<unistd.h>
#include	"TCP_server.hpp"
#include	"TCP_client.hpp"

TCP_server::TCP_server(std::string const &port) : ASocket(bind(port))
{
}

TCP_server::~TCP_server(void)
{
  close(m_fd);
}

int	TCP_server::aux_bind(struct addrinfo const *rp)
{
  if (rp == NULL)
    throw std::exception();
  int const	fd = ::socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
  if (fd == -1)
    {
      perror("socket()");
      return (aux_bind(rp->ai_next));
    }
  if (::bind(fd, rp->ai_addr, rp->ai_addrlen) != 0)
    {
      perror("bind()");
      if (::close(fd) == -1)
	perror("close()");
      return (aux_bind(rp->ai_next));
    }
  if (::listen(fd, 42) != 0)
    {
      perror("listen()");
      if (::close(fd) == -1)
	perror("close()");
      return (aux_bind(rp->ai_next));
    }
  return (fd);
}

int	TCP_server::bind(std::string const &port)
{
  struct addrinfo const	hints =
    {
      AI_PASSIVE,
      AF_UNSPEC,
      SOCK_STREAM,
      IPPROTO_TCP,
      0,
      NULL,
      NULL,
      NULL
    };
  struct addrinfo	*result;
  int	status = ::getaddrinfo(NULL, port.c_str(), &hints, &result);
  if (status != 0)
    {
      std::cerr << "getaddrinfo: " << gai_strerror(status) <<  std::endl;
      throw std::exception();
    }

  int	fd = aux_bind(result);
  ::freeaddrinfo(result);
  return (fd);
}

ITCP_client	&TCP_server::accept(void) const
{
  return (*new TCP_client(*this));
}
