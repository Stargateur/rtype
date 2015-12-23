//
// Time.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 21:04:15 2015 Bertrand-Rapello Baptiste
// Last update Wed Dec 23 13:11:24 2015 Antoine Plaskowski
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

bool	Time::set_second(intmax_t second)
{
  m_timespec.tv_sec = static_cast<time_t>(second);
  return (false);
}

intmax_t	Time::get_nano(void) const
{
  return (static_cast<intmax_t>(m_timespec.tv_nsec));
}

bool	Time::set_nano(intmax_t nano)
{
  m_timespec.tv_nsec = static_cast<time_t>(nano);
  return (false);
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

void	Time::add(ITime const &itime)
{
  m_timespec.tv_sec += itime.get_second();
  if (m_timespec.tv_nsec + itime.get_nano() >= NANO_BY_SEC)
    {
      m_timespec.tv_nsec += itime.get_nano();
      m_timespec.tv_nsec -= NANO_BY_SEC;
      m_timespec.tv_sec += 1;
    }
}

void	Time::sub(ITime const &itime)
{
  if (m_timespec.tv_nsec + m_timespec.tv_sec >= itime.get_nano() + itime.get_second())
    {
      m_timespec.tv_sec -= itime.get_second();
      m_timespec.tv_nsec -= itime.get_nano();
      if (m_timespec.tv_nsec < 0)
	{
	  m_timespec.tv_nsec = NANO_BY_SEC + m_timespec.tv_nsec;
	  m_timespec.tv_sec -= 1;
	}
    }
  else
    {
      Time swap(itime.get_second(), itime.get_nano());
      
      swap.m_timespec.tv_sec -= m_timespec.tv_sec;
      swap.m_timespec.tv_nsec -= m_timespec.tv_nsec;
      if (swap.m_timespec.tv_nsec < 0)
	{
	  swap.m_timespec.tv_nsec = NANO_BY_SEC + swap.m_timespec.tv_nsec;
	  swap.m_timespec.tv_sec -= 1;
	}
      set_nano(swap.get_nano());
      set_second(swap.get_second() * -1);
    }
}
