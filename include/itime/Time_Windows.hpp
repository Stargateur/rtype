//
// Time_Windows.hpp for Time_Windows in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <plasko_a@epitech.eu>
// 
// Started on  Sun Dec 27 01:01:39 2015 Antoine Plaskowski
// Last update Sun Dec 27 01:02:31 2015 Antoine Plaskowski
//

#ifndef	TIME_WINDOWS_HPP_
# define	TIME_WINDOWS_HPP

#include <windows.h>
#include "ITime.hpp"

class	TimeWindows : public ITime
{
public:
	TimeWindows(void);
	intmax_t	get_second(void) const;
	bool	set_second(intmax_t);
	intmax_t	get_nano(void) const;
	bool	set_nano(intmax_t);
	bool	now(void);
	ITime	&clone(void) const;
	~TimeWindows(void);
private:
	time_t m_second;
	WORD m_mili;
};

#endif	/* !TIME_WINDOWS_HPP */
