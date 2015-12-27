//
// Wall.cpp for Wall in /home/degand_a/Projects/rtype/source/server/Entity
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Wed Dec 23 11:41:43 2015 Alaric Degand
// Last update Sun Dec 27 13:43:20 2015 Antoine Plaskowski
//

#include	<list>
#include	<iostream>
#include	"ITime.hpp"
#include	"Wall.hpp"

Wall::Wall(std::list<IEntite *> const &ientites, uintmax_t id, uintmax_t team, uintmax_t x_max, uintmax_t y_max) :
  m_id(id),
  m_team(team),
  m_hp(5000),
  m_x(0),
  m_y(0),
  m_max_x(x_max),
  m_max_y(y_max)
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
  m_hp -= value;
}

void		Wall::colide(void)
{

}

intmax_t	Wall::get_x(void) const
{
  return (m_x);
}

intmax_t	Wall::get_y(void) const
{
  return (m_y);
}

uintmax_t	Wall::get_size_x(void) const
{
  return (10);
}

uintmax_t	Wall::get_size_y(void) const
{
  return (10);
}

uintmax_t	Wall::get_team(void) const
{
  return (m_team);
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

uintmax_t	Wall::get_id(void) const
{
  return (m_id);
}

IEntite	*new_ientite(std::list<IEntite *> const &ientites, uintmax_t id, uintmax_t team, uintmax_t x_max, uintmax_t y_max)
{
  return (new Wall(ientites, id, team, x_max, y_max));
}
