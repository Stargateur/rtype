//
// Wall.cpp for Wall in /home/degand_a/Projects/rtype/source/server/Entity
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Wed Dec 23 11:41:43 2015 Alaric Degand
// Last update Wed Dec 23 11:56:57 2015 Alaric Degand
//

#include	<list>
#include	"ITime.hpp"
#include	"Wall.hpp"

Wall::Wall(void)
{
  //initialiser les prop de l'objets et sa team
}

void		Wall::run(std::list<IEntite *> const &ientites, std::list<IEntite *> &new_ientites,
			  ITime const &time_elapsed, ITime &time_callback)
{
  
time_callback.
}

void		Wall::domage(uintmax_t value)
{

}

void		Wall::colide(void)
{

}

std::tuple<uintmax_t, uintmax_t, uintmax_t, uintmax_t> const	&Wall::get_property(void) const
{
  return (_prop);
}

uintmax_t	Wall::get_team(void) const
{
  return (_team);
}
