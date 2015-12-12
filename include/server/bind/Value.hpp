//
// Value.hpp for hell in /home/rousse_3/Project/rushhell/hell/devil/bind
// 
// Made by Roussel Rodolphe
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Nov 28 17:48:30 2015 Roussel Rodolphe
// Last update Sun Nov 29 00:16:13 2015 Roussel Rodolphe
//

#ifndef		VALUE_HPP_
# define	VALUE_HPP_

template<typename T = void>
class		Value
{
  T		_elem;

public:
  Value(T elem) :
    _elem(elem)
  {}
  
  T		&get(void)
  { return (_elem); };
  const T	&get(void) const
  { return (_elem); };
};

#endif
