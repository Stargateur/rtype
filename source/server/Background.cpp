//
// Background.cpp for Background in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Dec 26 15:02:29 2015 Antoine Plaskowski
// Last update Sat Dec 26 15:20:56 2015 Antoine Plaskowski
//

#include	"Background.hpp"

Background::Background(uintmax_t team, uintmax_t size_x, uintmax_t size_y) :
  m_team(team),
  m_property(std::make_tuple(0, 0, size_x, size_y))
{
}

Background::~Background(void)
{
}

void	Background::run(std::list<IEntite *> const &ientites, std::list<IEntite *> &new_ientites,
			ITime const &time_elapsed, ITime &time_callback)
{
}

void	Background::domage(uintmax_t value)
{
}

void	Background::colide(void)
{
}

std::tuple<uintmax_t, uintmax_t, uintmax_t, uintmax_t> const	&Background::get_property(void) const
{
  return (m_property);
}

uintmax_t	Background::get_team(void) const
{
  return (m_team);
}

File const	&Background::get_sound(void) const
{
  static File	sound("sprites/stars.jpg");
  return (sound);
}

File const	&Background::get_sprite(void) const
{
  static File	sprite("sprites/stars.jpg");
  return (sprite);
}

