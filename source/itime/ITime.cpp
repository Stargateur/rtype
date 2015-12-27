//
// ITime.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 22:05:31 2015 Bertrand-Rapello Baptiste
// Last update Sun Dec 27 01:40:35 2015 Antoine Plaskowski
//

#include "ITime.hpp"

ITime::ITime(void)
{
}

ITime::ITime(ITime const &itime)
{
  set_second(itime.get_second());
  set_nano(itime.get_nano());
}

ITime::~ITime(void)
{
}

ITime	&ITime::operator=(ITime const &itime)
{
  set_second(itime.get_second());
  set_nano(itime.get_nano());
  return (*this);
}

ITime	&ITime::operator+=(ITime const &itime)
{
  set_second(get_second() + itime.get_second());
  set_nano(get_nano() + itime.get_nano());
  return (*this);
}

ITime	&ITime::operator-=(ITime const &rhs)
{
  return (*this);
}

bool	operator!=(ITime const &lhs, ITime const &rhs)
{
  return (lhs.get_second() != rhs.get_second() && lhs.get_nano() != rhs.get_nano());
}
bool	operator==(ITime const &lhs, ITime const &rhs)
{
  return !(lhs != rhs);  
}

bool	operator<(ITime const &lhs, ITime const &rhs)
{
  if (lhs.get_second() < rhs.get_second())
    return (true);
  if (lhs.get_second() > rhs.get_second())
    return (false);
  return (lhs.get_nano() < rhs.get_nano());
}

bool	operator>(ITime const &lhs, ITime const &rhs)
{
  if (lhs.get_second() > rhs.get_second())
    return (true);
  if (lhs.get_second() < rhs.get_second())
    return (false);
  return (lhs.get_nano() > rhs.get_nano());
}
bool	operator<=(ITime const &lhs, ITime const &rhs)
{
  return !(lhs > rhs);
}

bool	operator>=(ITime const &lhs, ITime const &rhs)
{
  return !(lhs < rhs);
}
