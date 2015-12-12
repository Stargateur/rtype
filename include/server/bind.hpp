//
// bind.hpp for hell in /home/rousse_3/Project/rushhell/hell/devil/bind
// 
// Made by Roussel Rodolphe
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Nov 28 21:57:52 2015 Roussel Rodolphe
// Last update Sat Dec 12 19:20:06 2015 Roussel Rodolphe
//

#ifndef			BIND_HPP_
# define		BIND_HPP_

# include		"bind/Trait.hpp"
# include		"bind/Caller.hpp"

template<typename ReturnType>
Caller<ReturnType, ReturnType(*)(), typename Traits0::Type >
bind(ReturnType(*f)())
{
  typedef TypeList0 ListType;
  ListType l;
  return Caller<ReturnType, ReturnType(*)(), ListType>(f, l);
}

template<typename ReturnType, typename Class>
Caller<ReturnType, ReturnType(Class::*)(), typename Traits0::Type, Class>
bind(ReturnType(Class::*f)(), Class *c)
{
  typedef TypeList0 ListType;
  ListType l;
  return Caller<ReturnType, ReturnType(Class::*)(), ListType, Class>(f, l, c);
}

template<typename ReturnType, typename Class>
Caller<ReturnType, ReturnType(Class::*)() const, typename Traits0::Type, const Class>
bind(ReturnType(Class::*f)() const, const Class *c)
{
  typedef TypeList0 ListType;
  ListType l;
  return Caller<ReturnType, ReturnType(Class::*)() const, ListType, const Class>(f, l, c);
}

template<typename ReturnType, typename X1, typename Param1>
Caller<ReturnType, ReturnType(*)(X1), typename Traits1<Param1>::Type >
bind(ReturnType(*f)(X1), Param1 p1)
{
  typedef typename GetType<Param1>::Type P1;
  typedef TypeList1 <P1> ListType;
  ListType l(p1);
  return Caller<ReturnType, ReturnType(*)(X1), ListType>(f, l);
}

template<typename ReturnType, typename X1, typename Param1, typename Class>
Caller<ReturnType, ReturnType(Class::*)(X1), typename Traits1<Param1>::Type, Class>
bind(ReturnType(Class::*f)(X1), Class *c, Param1 p1)
{
  typedef typename GetType<Param1>::Type P1;
  typedef TypeList1 <P1> ListType;
  ListType l(p1);
  return Caller<ReturnType, ReturnType(Class::*)(X1), ListType, Class>(f, l, c);
}

template<typename ReturnType, typename X1, typename Param1, typename Class>
Caller<ReturnType, ReturnType(Class::*)(X1) const, typename Traits1<Param1>::Type, const Class>
bind(ReturnType(Class::*f)(X1) const, const Class *c, Param1 p1)
{
  typedef typename GetType<Param1>::Type P1;
  typedef TypeList1 <P1> ListType;
  ListType l(p1);
  return Caller<ReturnType, ReturnType(Class::*)(X1) const, ListType, const Class>(f, l, c);
}

template<typename ReturnType, typename X1, typename X2, typename Param1, typename Param2>
Caller<ReturnType, ReturnType(*)(X1, X2), typename Traits2<Param1, Param2>::Type >
bind(ReturnType(*f)(X1, X2), Param1 p1, Param2 p2)
{
  typedef typename GetType<Param1>::Type P1;
  typedef typename GetType<Param2>::Type P2;
  typedef TypeList2 <P1, P2> ListType;
  ListType l(p1, p2);
  return Caller<ReturnType, ReturnType(*)(X1, X2), ListType>(f, l);
}

template<typename ReturnType, typename X1, typename X2, typename Param1, typename Param2, typename Class>
Caller<ReturnType, ReturnType(Class::*)(X1, X2), typename Traits2<Param1, Param2>::Type, Class >
bind(ReturnType(Class::*f)(X1, X2), Class *c, Param1 p1, Param2 p2)
{
  typedef typename GetType<Param1>::Type P1;
  typedef typename GetType<Param2>::Type P2;
  typedef TypeList2 <P1, P2> ListType;
  ListType l(p1, p2);
  return Caller<ReturnType, ReturnType(Class::*)(X1, X2), ListType, Class>(f, l, c);
}

template<typename ReturnType, typename X1, typename X2, typename Param1, typename Param2, typename Class>
Caller<ReturnType, ReturnType(Class::*)(X1, X2) const, typename Traits2<Param1, Param2>::Type, const Class >
bind(ReturnType(Class::*f)(X1, X2) const, const Class *c, Param1 p1, Param2 p2)
{
  typedef typename GetType<Param1>::Type P1;
  typedef typename GetType<Param2>::Type P2;
  typedef TypeList2 <P1, P2> ListType;
  ListType l(p1, p2);
  return Caller<ReturnType, ReturnType(Class::*)(X1, X2) const, ListType, const Class>(f, l, c);
}

template<typename ReturnType, typename X1, typename X2, typename X3, typename Param1, typename Param2, typename Param3>
Caller<ReturnType, ReturnType(*)(X1, X2, X3), typename Traits3<Param1, Param2, Param3>::Type >
bind(ReturnType(*f)(X1, X2, X3), Param1 p1, Param2 p2, Param3 p3)
{
  typedef typename GetType<Param1>::Type P1;
  typedef typename GetType<Param2>::Type P2;
  typedef typename GetType<Param3>::Type P3;
  typedef TypeList3 <P1, P2, P3> ListType;
  ListType l(p1, p2, p3);
  return Caller<ReturnType, ReturnType(*)(X1, X2, X3), ListType>(f, l);
}

template<typename ReturnType, typename X1, typename X2, typename X3, typename Param1, typename Param2, typename Param3, typename Class>
Caller<ReturnType, ReturnType(Class::*)(X1, X2, X3), typename Traits3<Param1, Param2, Param3>::Type, Class >
bind(ReturnType(Class::*f)(X1, X2, X3), Class *c, Param1 p1, Param2 p2, Param3 p3)
{
  typedef typename GetType<Param1>::Type P1;
  typedef typename GetType<Param2>::Type P2;
  typedef typename GetType<Param3>::Type P3;
  typedef TypeList3 <P1, P2, P3> ListType;
  ListType l(p1, p2, p3);
  return Caller<ReturnType, ReturnType(Class::*)(X1, X2, X3), ListType>(f, l, c);
}

template<typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename Param1, typename Param2, typename Param3, typename Param4>
Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4), typename Traits4<Param1, Param2, Param3, Param4>::Type >
bind(ReturnType(*f)(X1, X2, X3, X4), Param1 p1, Param2 p2, Param3 p3, Param4 p4)
{
  typedef typename GetType<Param1>::Type P1;
  typedef typename GetType<Param2>::Type P2;
  typedef typename GetType<Param3>::Type P3;
  typedef typename GetType<Param4>::Type P4;
  typedef TypeList4 <P1, P2, P3, P4> ListType;
  ListType l(p1, p2, p3, p4);
  return Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4), ListType>(f, l);
}

template<typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename X5, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5>
Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4, X5), typename Traits5<Param1, Param2, Param3, Param4, Param5>::Type >
bind(ReturnType(*f)(X1, X2, X3, X4, X5), Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
{
  typedef typename GetType<Param1>::Type P1;
  typedef typename GetType<Param2>::Type P2;
  typedef typename GetType<Param3>::Type P3;
  typedef typename GetType<Param4>::Type P4;
  typedef typename GetType<Param5>::Type P5;
typedef TypeList5 <P1, P2, P3, P4, P5> ListType;
ListType l(p1, p2, p3, p4, p5);
return Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4, X5), ListType>(f, l);
}

template<typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename X5, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Class>
Caller<ReturnType, ReturnType(Class::*)(X1, X2, X3, X4, X5), typename Traits5<Param1, Param2, Param3, Param4, Param5>::Type, Class >
bind(ReturnType(Class::*f)(X1, X2, X3, X4, X5), Class *c, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
{
  typedef typename GetType<Param1>::Type P1;
  typedef typename GetType<Param2>::Type P2;
  typedef typename GetType<Param3>::Type P3;
  typedef typename GetType<Param4>::Type P4;
  typedef typename GetType<Param5>::Type P5;
  typedef TypeList5 <P1, P2, P3, P4, P5> ListType;
  ListType l(p1, p2, p3, p4, p5);
  return Caller<ReturnType, ReturnType(Class::*)(X1, X2, X3, X4, X5), ListType, Class>(f, l, c);
}

template<typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename X5, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Class>
Caller<ReturnType, ReturnType(Class::*)(X1, X2, X3, X4, X5) const, typename Traits5<Param1, Param2, Param3, Param4, Param5>::Type, const Class >
bind(ReturnType(Class::*f)(X1, X2, X3, X4, X5) const, const Class *c, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
{
  typedef typename GetType<Param1>::Type P1;
  typedef typename GetType<Param2>::Type P2;
  typedef typename GetType<Param3>::Type P3;
  typedef typename GetType<Param4>::Type P4;
  typedef typename GetType<Param5>::Type P5;
  typedef TypeList5 <P1, P2, P3, P4, P5> ListType;
  ListType l(p1, p2, p3, p4, p5);
  return Caller<ReturnType, ReturnType(Class::*)(X1, X2, X3, X4, X5), ListType, const Class>(f, l, c);
}

template<typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6>
Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4, X5, X6), typename Traits6<Param1, Param2, Param3, Param4, Param5, Param6>::Type >
bind(ReturnType(*f)(X1, X2, X3, X4, X5, X6), Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
{
  typedef typename GetType<Param1>::Type P1;
  typedef typename GetType<Param2>::Type P2;
  typedef typename GetType<Param3>::Type P3;
  typedef typename GetType<Param4>::Type P4;
  typedef typename GetType<Param5>::Type P5;
  typedef typename GetType<Param6>::Type P6;
typedef TypeList6 <P1, P2, P3, P4, P5, P6> ListType;
ListType l(p1, p2, p3, p4, p5, p6);
return Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4, X5, X6), ListType>(f, l);
}

template<typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6, typename Class>
Caller<ReturnType, ReturnType(Class::*)(X1, X2, X3, X4, X5, X6), typename Traits6<Param1, Param2, Param3, Param4, Param5, Param6>::Type, Class >
bind(ReturnType(Class::*f)(X1, X2, X3, X4, X5, X6), Class *c, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
{
  typedef typename GetType<Param1>::Type P1;
  typedef typename GetType<Param2>::Type P2;
  typedef typename GetType<Param3>::Type P3;
  typedef typename GetType<Param4>::Type P4;
  typedef typename GetType<Param5>::Type P5;
  typedef typename GetType<Param6>::Type P6;
  typedef TypeList6 <P1, P2, P3, P4, P5, P6> ListType;
  ListType l(p1, p2, p3, p4, p5, p6);
  return Caller<ReturnType, ReturnType(Class::*)(X1, X2, X3, X4, X5, X6), ListType, Class>(f, l, c);
}

template<typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6, typename Class>
Caller<ReturnType, ReturnType(Class::*)(X1, X2, X3, X4, X5, X6) const, typename Traits6<Param1, Param2, Param3, Param4, Param5, Param6>::Type, const Class >
bind(ReturnType(Class::*f)(X1, X2, X3, X4, X5, X6) const, const Class *c, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
{
  typedef typename GetType<Param1>::Type P1;
  typedef typename GetType<Param2>::Type P2;
  typedef typename GetType<Param3>::Type P3;
  typedef typename GetType<Param4>::Type P4;
  typedef typename GetType<Param5>::Type P5;
  typedef typename GetType<Param6>::Type P6;
  typedef TypeList6 <P1, P2, P3, P4, P5, P6> ListType;
  ListType l(p1, p2, p3, p4, p5, p6);
  return Caller<ReturnType, ReturnType(Class::*)(X1, X2, X3, X4, X5, X6) const, ListType, const Class>(f, l, c);
}

#endif
