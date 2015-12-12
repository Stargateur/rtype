//
// Ref.hpp for Hell in /home/rousse_3/Project/rushhell/hell/devil/bind
// 
// Made by Roussel Rodolphe
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun Nov 29 14:18:01 2015 Roussel Rodolphe
// Last update Sat Dec 12 18:03:32 2015 Roussel Rodolphe
//

#ifndef		REF_HPP_
# define	REF_HPP_

template<typename T>
class		Ref
{
private:
  T		&_ref;
public:
  Ref(T &ref) :
    _ref(ref)
  {}

  operator T&()
  {
    return (_ref);
  }
};

#endif
