//
// Time.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 21:04:15 2015 Bertrand-Rapello Baptiste
// Last update Sun Dec 27 01:43:01 2015 Antoine Plaskowski
//

#include	<stdio.h>
#include	"Time.hpp"

Time::Time(intmax_t second, intmax_t nano) :
  m_timespec({second, nano})
{
}

Time::~Time(void)
{
}

intmax_t	Time::get_second(void) const
{
  return (static_cast<intmax_t>(m_timespec.tv_sec));
}

void	Time::set_second(intmax_t second)
{
  m_timespec.tv_sec = static_cast<time_t>(second);
}

intmax_t	Time::get_nano(void) const
{
  return (static_cast<intmax_t>(m_timespec.tv_nsec));
}

void	Time::set_nano(intmax_t nano)
{
  m_timespec.tv_nsec = static_cast<time_t>(nano);
  if (get_nano() >= ITime::nano_by_second)
    {
      set_nano(get_nano() - ITime::nano_by_second);
      if (get_second() >= 0)
	set_second(get_second() + 1);
      else
	set_second(get_second() + 1);
    }
  else if (get_nano() < 0)
    {
      set_nano(get_nano() + ITime::nano_by_second);
      set_second(get_second() - 1);
    }
}

bool	Time::now(void)
{
  if (clock_gettime(CLOCK_REALTIME, &m_timespec) == -1)
    return true;
  return false;
}

ITime	&Time::clone(void) const
{
  return (*new Time(get_second(), get_nano()));
}

ITime	*new_itime(void)
{
  return (new Time());
}
