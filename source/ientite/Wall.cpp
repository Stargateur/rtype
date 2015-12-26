//
// Wall.cpp for Wall in /home/degand_a/Projects/rtype/source/server/Entity
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Wed Dec 23 11:41:43 2015 Alaric Degand
// Last update Sat Dec 26 14:51:00 2015 Antoine Plaskowski
//

#include	<list>
#include	<iostream>
#include	"ITime.hpp"
#include	"Wall.hpp"

Wall::Wall(std::list<IEntite *> const &ientites, uintmax_t team, uintmax_t x_max, uintmax_t y_max) :
  _team(team),
  _hp(5000),
  _property(std::make_tuple(x_max, rand() % 2 * y_max, x_max / 10, y_max / 5))
{
  // while (this.check_colide(ientites))
  //   {
  //     y_max--;
  //     _property<1> = (rand() % 2) * y_max;
  //   }
}

void		Wall::run(std::list<IEntite *> const &ientites, std::list<IEntite *> &new_ientites,
			  ITime const &time_elapsed, ITime &time_callback)
{
  // Time		calc(_delay.get_second(), _delay.get_nano());

  // calc.sub(time_elapsed);
  // if (calc.get_second() == 0 && calc.get_nano() == 0)
  //   {
  //     _property<0> -= 1;
  //     if (check_colide(ientites))
  // 	colide();
  //     time_callback.set_second(_delay.get_second());
  //     time_callback.set_nano(_delay.get_nano());
  //   }
  // else
  //   {
  //     time_callback.set_second(calc.get_second());
  //     time_callback.set_nano(calc.get_nano());
  //   }
}

void		Wall::domage(uintmax_t value)
{
  _hp -= value;
}

void		Wall::colide(void)
{

}

std::tuple<uintmax_t, uintmax_t, uintmax_t, uintmax_t> const	&Wall::get_property(void) const
{
  return (_property);
}

uintmax_t	Wall::get_team(void) const
{
  return (_team);
}

File const	&Wall::get_sound(void) const
{
  static File const	sound("font/vol.png");
  return (sound);
}

File const	&Wall::get_sprite(void) const
{
  static File const	sprite("font/vol.png");
  return (sprite);
}

bool		Wall::check_colide(std::list<IEntite *> const &ientites) const
{
  std::tuple<uintmax_t, uintmax_t, uintmax_t, uintmax_t> to_check;
  
  // for (std::list<IEntite *>::iterator it = ientites.begin(); it != ientites.end(); it++)
  //   {
  //     to_check = it.get_property();
  //     if (_property<0> < to_check<0> + to_check<2> &&
  // 	  _property<0> + _property<2> > to_check<0> &&
  // 	  _property<1> < to_check<1> + to_check<3> &&
  // 	  _property<1> + _property<3> > to_check<1>)
  // 	return (true);
  //   }
  return (false);
}

IEntite       *new_ientite(std::list<IEntite *> const &ientites, uintmax_t team, uintmax_t x_max, uintmax_t y_max)
{
  return (new Wall(ientites, team, x_max, y_max));
}
