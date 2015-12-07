//
// UDP_client.cpp for UDP_client in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 12:09:50 2015 Antoine Plaskowski
// Last update Mon Dec  7 17:28:07 2015 Antoine Plaskowski
//

#include	"UDP_client.hpp"

UDP_client::UDP_client(u_sockaddr sockaddr, socklen_t len) :
  m_host(),
  m_sockaddr(sockaddr),
  m_len(len)
{
}

UDP_client::UDP_client(std::string const &host) :
  m_host(host),
  m_sockaddr({}),
  m_len(0)
{
}

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
