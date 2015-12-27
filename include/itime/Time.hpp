//
// Time.hpp for Time.hpp in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <plasko_a@epitech.eu>
// 
// Started on  Sun Dec 27 01:06:19 2015 Antoine Plaskowski
// Last update Sun Dec 27 01:06:20 2015 Antoine Plaskowski
//

#ifndef TIME_HPP_
# define TIME_HPP_

# include	<ctime>
# include	<cstdint>
# include	"ITime.hpp"

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
  void	add(ITime const &itime);
  void	sub(ITime const &itime);
  intmax_t	cmp(ITime const &itime) const;
private:
  struct timespec	m_timespec;  
};

#endif	/* !TIME_HPP_ */
