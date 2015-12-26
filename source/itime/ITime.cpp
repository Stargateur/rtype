//
// ITime.cpp for  in /home/bbr2394/renduTek3/cpp_spider/source
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 22:05:31 2015 Bertrand-Rapello Baptiste
// Last update Sat Dec 26 17:17:19 2015 Antoine Plaskowski
//

#include "ITime.hpp"

ITime::~ITime()
{
}

ITime	&ITime::operator=(ITime const &itime)
{
  set_second(itime.get_second());
  set_nano(itime.get_nano());
	return (*this);
}
