//
// Standard.cpp for Standard in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 06:01:34 2015 Antoine Plaskowski
// Last update Fri Nov 20 06:48:10 2015 Antoine Plaskowski
//

#include	<unistd.h>
#include	<exception>
#include	"Standard.hpp"

Standard::Standard(IStandard::io io) : IStandard(io_to_fd(io))
{
}

uintmax_t	Standard::read(uint8_t &data, uintmax_t size) const
{
  ssize_t	ret = ::read(m_fd, &data, size);
  if (ret < 0)
    throw std::exception();
  return (static_cast<uintmax_t>(ret));
}

uintmax_t	Standard::write(uint8_t const &data, uintmax_t size) const
{
  ssize_t	ret = ::write(m_fd, &data, size);
  if (ret < 0)
    throw std::exception();
  return (static_cast<uintmax_t>(ret));
}

int	Standard::io_to_fd(IStandard::io io)
{
  switch (io)
    {
    case IStandard::In:
      return (0);
    case IStandard::Out:
      return (1);
    case IStandard::Err:
      return (2);
    }
  throw std::exception();
}
