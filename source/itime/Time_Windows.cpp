//
// Time_Windows.cpp for Time_Windows in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <plasko_a@epitech.eu>
// 
// Started on  Sun Dec 27 01:00:23 2015 Antoine Plaskowski
// Last update Sun Dec 27 02:05:24 2015 Antoine Plaskowski
//

#include <ctime>
#include "Time_Windows.hpp"

TimeWindows::TimeWindows(void)
{
}

intmax_t	TimeWindows::get_second(void) const
{
  return (m_second);
}

void	TimeWindows::set_second(intmax_t second)
{
  m_second = second;
}

intmax_t	TimeWindows::get_nano(void) const
{
  return (m_milli * milli_by_nano);
}

void	TimeWindows::set_nano(intmax_t nano)
{
  m_milli = nano / milli_by_nano;
  if (get_nano() >= ITime::nano_by_second)
    {
      if (get_second() >= 0)
	set_second(get_second() + 1);
      else
	set_second(get_second() - 1);
      set_nano(get_nano() - ITime::nano_by_second);
    }
  else if (get_nano() < 0)
    {
      if (get_second() >= 0)
	set_second(get_second() - 1);
      else        set_second(get_second() + 1);
      set_nano(get_nano() + ITime::nano_by_second);
    }
}

bool	TimeWindows::now(void)
{
  SYSTEMTIME SystemTime;
  m_second = time(NULL);
  GetSystemTime(&SystemTime);
  m_milli = SystemTime.wMilliseconds;
  return (false);
}

ITime	&TimeWindows::clone(void) const
{
  return (*new TimeWindows());
}

TimeWindows::~TimeWindows(void)
{
}

extern "C" __declspec(dllexport)
ITime	&new_itime(void)
{
  return (*new TimeWindows());
}
