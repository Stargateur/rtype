//
// Trait.hpp for rush in /home/rousse_3/Project/rushhell/hell/devil/bind
// 
// Made by Roussel Rodolphe
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Nov 28 22:21:53 2015 Roussel Rodolphe
// Last update Sun Nov 29 07:03:23 2015 Roussel Rodolphe
//

#ifndef		TRAIT_HPP_
# define	TRAIT_HPP_

# include	"GetType.hpp"
# include	"TypeList.hpp"

struct Traits0
{
  typedef TypeList0 Type;
};

template<typename P1>
struct Traits1
{
  typedef typename GetType<P1>::Type Type_Parameter_1;
  typedef TypeList1<Type_Parameter_1> Type;
};

template<typename P1, typename P2>
struct Traits2
{
  typedef typename GetType<P1>::Type Type_Parameter_1;
  typedef typename GetType<P2>::Type Type_Parameter_2;
  typedef TypeList2<Type_Parameter_1, Type_Parameter_2> Type;
};

template<typename P1, typename P2, typename P3>
struct Traits3
{
  typedef typename GetType<P1>::Type Type_Parameter_1;
  typedef typename GetType<P2>::Type Type_Parameter_2;
  typedef typename GetType<P3>::Type Type_Parameter_3;
  typedef TypeList3<Type_Parameter_1, Type_Parameter_2, Type_Parameter_3> Type;
};

template<typename P1, typename P2, typename P3, typename P4>
struct Traits4
{
  typedef typename GetType<P1>::Type Type_Parameter_1;
  typedef typename GetType<P2>::Type Type_Parameter_2;
  typedef typename GetType<P3>::Type Type_Parameter_3;
  typedef typename GetType<P4>::Type Type_Parameter_4;
  typedef TypeList4<Type_Parameter_1, Type_Parameter_2, Type_Parameter_3, Type_Parameter_4> Type;
};

template<typename P1, typename P2, typename P3, typename P4, typename P5>
struct Traits5
{
  typedef typename GetType<P1>::Type Type_Parameter_1;
  typedef typename GetType<P2>::Type Type_Parameter_2;
  typedef typename GetType<P3>::Type Type_Parameter_3;
  typedef typename GetType<P4>::Type Type_Parameter_4;
  typedef typename GetType<P5>::Type Type_Parameter_5;
  typedef TypeList5<Type_Parameter_1, Type_Parameter_2, Type_Parameter_3, Type_Parameter_4, Type_Parameter_5> Type;
};

template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
struct Traits6
{
  typedef typename GetType<P1>::Type Type_Parameter_1;
  typedef typename GetType<P2>::Type Type_Parameter_2;
  typedef typename GetType<P3>::Type Type_Parameter_3;
  typedef typename GetType<P4>::Type Type_Parameter_4;
  typedef typename GetType<P5>::Type Type_Parameter_5;
  typedef typename GetType<P5>::Type Type_Parameter_6;
typedef TypeList6<Type_Parameter_1, Type_Parameter_2, Type_Parameter_3, Type_Parameter_4, Type_Parameter_5, Type_Parameter_6> Type;
};

#endif
