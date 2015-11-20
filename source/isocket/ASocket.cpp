//
// ASocket.cpp for ASocket in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:43:34 2015 Antoine Plaskowski
// Last update Fri Nov 20 06:12:20 2015 Antoine Plaskowski
//

#include	<algorithm>
#include	<exception>
#include	"ASocket.hpp"

fd_set	ASocket::m_readfds = {};
fd_set	ASocket::m_writefds = {};
int	ASocket::m_nfds = -1;

ASocket::ASocket(int fd) : m_fd(fd)
{
}

ASocket::~ASocket(void)
{
  FD_CLR(m_fd, &m_writefds);
  FD_CLR(m_fd, &m_readfds);
}

bool	ASocket::can_read(void) const
{
  bool	ret = FD_ISSET(m_fd, &m_readfds);
  FD_CLR(m_fd, &m_readfds);
  return (ret);
}

bool	ASocket::can_write(void) const
{
  bool	ret = FD_ISSET(m_fd, &m_writefds);
  FD_CLR(m_fd, &m_writefds);
  return (ret);
}

bool	ASocket::want_read(void) const
{
  FD_SET(m_fd, &m_readfds);
  m_nfds = std::max<int>(m_nfds, m_fd);
  return (false);
}

bool	ASocket::want_write(void) const
{
  FD_SET(m_fd, &m_writefds);
  m_nfds = std::max<int>(m_nfds, m_fd);
  return (false);
}

void	ASocket::select(ITime const *timeout)
{
  int   ret;

  if (timeout == nullptr)
    ret = pselect(m_nfds + 1, &m_readfds, &m_writefds, NULL, NULL, NULL);
  else
    {
      struct timespec   time = {timeout->get_second(), timeout->get_nano()};
      ret = pselect(m_nfds + 1, &m_readfds, &m_writefds, NULL, &time, NULL);
    }
  m_nfds = -1;
  if (ret == -1)
    {
      perror("select()");
      throw std::exception();
    }
}
