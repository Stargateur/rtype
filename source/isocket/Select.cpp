//
// Select.cpp for Select in /home/plasko_a/projet/cplusplus/rtype/source/isocket
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Dec  8 14:01:13 2015 Antoine Plaskowski
// Last update Tue Dec  8 15:47:33 2015 Antoine Plaskowski
//

#include	<algorithm>
#include	<cstring>
#include	<cerrno>
#include	"Select.hpp"

Select::Select(void) :
  m_readfds({}),
  m_writefds({}),
  m_nfds(-1)
{
}

bool    Select::can_read(ISocket const &socket)
{
  if (socket.get_fd() >= FD_SETSIZE)
    throw Select_exception(strerror(EDOM));
  bool  ret = FD_ISSET(socket.get_fd(), &m_readfds);
  FD_CLR(socket.get_fd(), &m_readfds);
  return (ret);
}

bool    Select::can_write(ISocket const &socket)
{
  if (socket.get_fd() >= FD_SETSIZE)
    throw Select_exception(strerror(EDOM));
  bool  ret = FD_ISSET(socket.get_fd(), &m_writefds);
  FD_CLR(socket.get_fd(), &m_writefds);
  return (ret);
}

void    Select::want_read(ISocket const &socket)
{
  if (socket.get_fd() >= FD_SETSIZE)
    throw Select_exception(strerror(EDOM));
  FD_SET(socket.get_fd(), &m_readfds);
  m_nfds = std::max<int>(m_nfds, socket.get_fd());
}

void    Select::want_write(ISocket const &socket)
{
  if (socket.get_fd() >= FD_SETSIZE)
    throw Select_exception(strerror(EDOM));
  FD_SET(socket.get_fd(), &m_writefds);
  m_nfds = std::max<int>(m_nfds, socket.get_fd());
}

void    Select::select(ITime const *timeout)
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
    throw Select_exception(strerror(errno));
}

Select_exception::Select_exception(char const *what) :
  m_what(what)
{
}

char const	*Select_exception::what(void) const noexcept
{
  return (m_what);
}
