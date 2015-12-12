//
// Function.hpp for Function in /home/bury_a/rendu/rushhell/charon/etape2
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Sat Nov 28 11:13:23 2015 Anthony Bury
// Last update Sat Dec 12 19:14:53 2015 Roussel Rodolphe
//

#ifndef		FUNCTION_HPP_
# define	FUNCTION_HPP_

template <typename Signature>
class Function;

template <typename T, typename U>
class Function<T(U)>
{
  class Callable
  {
  public:
    virtual T operator()(U p0) = 0;
  };
  class FuncPtr : public Callable
  {
    T (*m_func)(U);
  public:
    FuncPtr(T (*func)(U)) : m_func(func) {}
    T operator()(U p0)
    {
      return (this->m_func(p0));
    }
  };
  template <typename V>
  class Object : public Callable
  {
    V object;
  public:
    Object(V obj) : object(obj) {}
    T operator()(U p0)
    {
      return (this->object(p0));
    }
  };
  Callable *call;

public:
  Function(T (*func)(U)) : call(new FuncPtr(func)) {}
  template <typename V>
  Function(V obj) : call(new Object<V>(obj)) {}
  ~Function(void){}

public:
  Function operator=(Function<T(U)> copy)
  {
    this->call = copy.call;
    return (*this);
  }

  T operator()(U p0)
  {
    return ((*this->call)(p0));
  }
};

#endif		/* !FUNCTION_HPP_ */
