//
// Background.cpp for Background in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Dec 26 15:02:29 2015 Antoine Plaskowski
// Last update Sun Dec 27 13:51:51 2015 Antoine Plaskowski
//

#include	"Background.hpp"

Background::Background(uintmax_t id, uintmax_t team, uintmax_t max_x, uintmax_t max_y) :
  m_id(id),
  m_team(team),
  m_x(0),
  m_y(0),
  m_max_x(max_x),
  m_max_y(max_y)
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

intmax_t	Background::get_x(void) const
{
  return (m_x);
}

intmax_t	Background::get_y(void) const
{
  return (m_y);
}

uintmax_t	Background::get_size_x(void) const
{
  return (1920);
}

uintmax_t	Background::get_size_y(void) const
{
  return (1080);
}

uintmax_t	Background::get_team(void) const
{
  return (m_team);
}

uintmax_t	Background::get_id(void) const
{
  return (m_id);
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
