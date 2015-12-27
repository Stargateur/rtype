//
// Time_Windows.cpp for Time_Windows in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <plasko_a@epitech.eu>
// 
// Started on  Sun Dec 27 01:00:23 2015 Antoine Plaskowski
// Last update Sun Dec 27 01:34:56 2015 Antoine Plaskowski
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
  return (false);
}

intmax_t	TimeWindows::get_nano(void) const
{
  return (m_mili * 1000000);
}

void	TimeWindows::set_nano(intmax_t nano)
{
  m_mili = nano / 1000000;
  return (false);
}

bool	TimeWindows::now(void)
{
  SYSTEMTIME SystemTime;
  m_second = time(NULL);
  GetSystemTime(&SystemTime);
  m_mili = SystemTime.wMilliseconds;
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
