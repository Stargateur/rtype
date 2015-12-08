//
// ASocket.cpp for ASocket in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:43:34 2015 Antoine Plaskowski
// Last update Tue Dec  8 14:03:27 2015 Antoine Plaskowski
//

#include	<algorithm>
#include	<exception>
#include	"ASocket.hpp"

ASocket::ASocket(int fd) : m_fd(fd)
{
}

ASocket::~ASocket(void)
{
}

int	ASocket::get_fd(void) const
{
  return (m_fd);
}
