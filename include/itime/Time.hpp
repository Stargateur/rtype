//
// Time.hh for $ in /home/bbr2394/renduTek3/cpp_spider/include
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Wed Oct 21 20:57:19 2015 Bertrand-Rapello Baptiste
// Last update Tue Dec 22 16:43:42 2015 Alaric Degand
//

#ifndef TIME_HPP_
# define TIME_HPP_

#include <ctime>
#include <cstdint>
#include "ITime.hpp"

# define        NANO_BY_SEC     (1000000000)

class Time : public ITime
{
public:
  Time(intmax_t second = 0, intmax_t nano = 0);
  ~Time(void);
public:
  intmax_t	get_second(void) const;
  bool	set_second(intmax_t second);
  intmax_t	get_nano(void) const;
  bool	set_nano(intmax_t nano);
  bool	now(void);
  ITime	&clone(void) const;
  void	add(ITime &, ITime const &);
private:
  struct timespec	m_timespec;  
};

#endif
