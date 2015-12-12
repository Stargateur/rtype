//
// GetType.hpp for hell in /home/rousse_3/Project/rushhell/hell/devil/bind
// 
// Made by Roussel Rodolphe
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Nov 28 18:03:01 2015 Roussel Rodolphe
// Last update Sat Nov 28 18:06:05 2015 Roussel Rodolphe
//

#ifndef		GETTYPE_HPP_
# define	GETTYPE_HPP_

# include	"Value.hpp"

template<typename T>
struct		GetType
{
  typedef	Value<T>	Type;
};

#endif
