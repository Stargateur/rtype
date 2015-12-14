//
// Caller.hpp for rush in /home/rousse_3/Project/rushhell/hell/devil/bind
// 
// Made by Roussel Rodolphe
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Nov 28 22:19:59 2015 Roussel Rodolphe
// Last update Sun Nov 29 19:20:06 2015 Roussel Rodolphe
//

#ifndef		CALLER_HPP_
# define	CALLER_HPP_

template<typename ReturnType, typename Callable, typename List, typename Class = void>
class Caller
{
private:
  Callable	_call;
  List		_l;
  Class		*_c;
public:
  Caller(Callable call, List l, Class *c) :
    _call(call),
    _l(l),
    _c(c)
  {}

  ReturnType	operator()()
  {
    return (_l(TypeTraits<ReturnType>(), _call, _l, _c));
  }

  template<typename P1>
  ReturnType	operator()(P1 p1)
  {
    typedef TypeList1 <P1> ListType;
    ListType l(p1);
    return (_l(TypeTraits<ReturnType>(), _call, l, _c));
  }

  template<typename P1, typename P2>
  ReturnType	operator()(P1 p1, P2 p2)
  {
    typedef TypeList2 <P1, P2> ListType;
    ListType l(p1, p2);
    return (_l(TypeTraits<ReturnType>(), _call, l, _c));
  }

  template<typename P1, typename P2, typename P3>
  ReturnType	operator()(P1 p1, P2 p2, P3 p3)
  {
    typedef TypeList3 <P1, P2, P3> ListType;
    ListType l(p1, p2, p3);
    return (_l(TypeTraits<ReturnType>(), _call, l, _c));
  }

  template<typename P1, typename P2, typename P3, typename P4>
  ReturnType	operator()(P1 p1, P2 p2, P3 p3, P4 p4)
  {
    typedef TypeList4 <P1, P2, P3, P4> ListType;
    ListType l(p1, p2, p3, p4);
    return (_l(TypeTraits<ReturnType>(), _call, l, _c));
  }

  template<typename P1, typename P2, typename P3, typename P4, typename P5>
  ReturnType	operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
  {
    typedef TypeList5 <P1, P2, P3, P4, P5> ListType;
    ListType l(p1, p2, p3, p4, p5);
    return (_l(TypeTraits<ReturnType>(), _call, l, _c));
  }

  template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
  ReturnType	operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
  {
    typedef TypeList6 <P1, P2, P3, P4, P5, P6> ListType;
    ListType l(p1, p2, p3, p4, p5, p6);
    return (_l(TypeTraits<ReturnType>(), _call, l, _c));
  }
};

template<typename ReturnType, typename Callable, typename List, typename Class>
class Caller<ReturnType, Callable, List, const Class>
{
private:
  Callable	_call;
  List		_l;
  const Class  	*_c;
public:
  Caller(Callable call, List l, const Class *c) :
    _call(call),
    _l(l),
    _c(c)
  {}

  ReturnType	operator()()
  {
    return (_l(TypeTraits<ReturnType>(), _call, _l, _c));
  }

  template<typename P1>
  ReturnType	operator()(P1 p1)
  {
    typedef TypeList1 <P1> ListType;
    ListType l(p1);
    return (_l(TypeTraits<ReturnType>(), _call, l, _c));
  }

  template<typename P1, typename P2>
  ReturnType	operator()(P1 p1, P2 p2)
  {
    typedef TypeList2 <P1, P2> ListType;
    ListType l(p1, p2);
    return (_l(TypeTraits<ReturnType>(), _call, l, _c));
  }

  template<typename P1, typename P2, typename P3>
  ReturnType	operator()(P1 p1, P2 p2, P3 p3)
  {
    typedef TypeList3 <P1, P2, P3> ListType;
    ListType l(p1, p2, p3);
    return (_l(TypeTraits<ReturnType>(), _call, l, _c));
  }

  template<typename P1, typename P2, typename P3, typename P4>
  ReturnType	operator()(P1 p1, P2 p2, P3 p3, P4 p4)
  {
    typedef TypeList4 <P1, P2, P3, P4> ListType;
    ListType l(p1, p2, p3, p4);
    return (_l(TypeTraits<ReturnType>(), _call, l, _c));
  }

  template<typename P1, typename P2, typename P3, typename P4, typename P5>
  ReturnType	operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
  {
    typedef TypeList5 <P1, P2, P3, P4, P5> ListType;
    ListType l(p1, p2, p3, p4, p5);
    return (_l(TypeTraits<ReturnType>(), _call, l, _c));
  }

  template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
  ReturnType	operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
  {
    typedef TypeList6 <P1, P2, P3, P4, P5, P6> ListType;
    ListType l(p1, p2, p3, p4, p5, p6);
    return (_l(TypeTraits<ReturnType>(), _call, l, _c));
  }
};

template<typename ReturnType, typename Callable, typename List>
class Caller<ReturnType, Callable, List, void>
{
private:
  Callable	_call;
  List		_l;
public:
  Caller(Callable call, List l) :
    _call(call),
    _l(l)
  {}
  
  ReturnType	operator()()
  {
    return (_l(TypeTraits<ReturnType>(), _call, _l));
  }

  template<typename P1>
  ReturnType	operator()(P1 p1)
  {
    typedef TypeList1 <P1> ListType;
    ListType l(p1);
    return (_l(TypeTraits<ReturnType>(), _call, l));
  }

  template<typename P1, typename P2>
  ReturnType	operator()(P1 p1, P2 p2)
  {
    typedef TypeList2 <P1, P2> ListType;
    ListType l(p1, p2);
    return (_l(TypeTraits<ReturnType>(), _call, l));
  }

  template<typename P1, typename P2, typename P3>
  ReturnType	operator()(P1 p1, P2 p2, P3 p3)
  {
    typedef TypeList3 <P1, P2, P3> ListType;
    ListType l(p1, p2, p3);
    return (_l(TypeTraits<ReturnType>(), _call, l));
  }

  template<typename P1, typename P2, typename P3, typename P4>
  ReturnType	operator()(P1 p1, P2 p2, P3 p3, P4 p4)
  {
    typedef TypeList4 <P1, P2, P3, P4> ListType;
    ListType l(p1, p2, p3, p4);
    return (_l(TypeTraits<ReturnType>(), _call, l));
  }

  template<typename P1, typename P2, typename P3, typename P4, typename P5>
  ReturnType	operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
  {
    typedef TypeList5 <P1, P2, P3, P4, P5> ListType;
    ListType l(p1, p2, p3, p4, p5);
    return (_l(TypeTraits<ReturnType>(), _call, l));
  }

  template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
  ReturnType	operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
  {
    typedef TypeList6 <P1, P2, P3, P4, P5, P6> ListType;
    ListType l(p1, p2, p3, p4, p5, p6);
    return (_l(TypeTraits<ReturnType>(), _call, l));
  }
};

#endif
