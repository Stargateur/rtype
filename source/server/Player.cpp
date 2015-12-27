//
// Player.cpp for Player in /home/plasko_a/projet/cplusplus/rtype/source/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Dec 23 17:18:36 2015 Antoine Plaskowski
// Last update Sun Dec 27 13:52:22 2015 Antoine Plaskowski
//

#include	"Player.hpp"

Player::Player(File const &sprite, File const &sound, std::string const &login, uintmax_t id, uintmax_t team, intmax_t x, intmax_t y, uintmax_t size_x, uintmax_t size_y, uintmax_t max_x, uintmax_t max_y) :
  IEntite(),
  m_id(id),
  m_sprite(sprite),
  m_sound(sound),
  m_login(login),
  m_team(team),
  m_x(x),
  m_y(y),
  m_size_x(size_x),
  m_size_y(size_y),
  m_max_x(max_x),
  m_max_y(max_y),
  m_hp(3),
  m_vitesse(5)
{
}

void	Player::run(std::list<IEntite *> const &ientites, std::list<IEntite *> &new_ientites,
		    ITime const &time_elapsed, ITime &time_callback)
{
  if (m_hp == 0)
    throw std::exception();
}

void	Player::domage(uintmax_t value)
{
  m_hp = m_hp == 0 || m_hp <= value ? 0 : m_hp - value;
}

void	Player::colide(void)
{
  m_hp = 0;
}

intmax_t	Player::get_x(void) const
{
  return (m_x);
}

intmax_t	Player::get_y(void) const
{
  return (m_y);
}

uintmax_t	Player::get_size_x(void) const
{
  return (m_size_x);
}

uintmax_t	Player::get_size_y(void) const
{
  return (m_size_y);
}

uintmax_t	Player::get_team(void) const
{
  return (m_team);
}

uintmax_t	Player::get_id(void) const
{
  return (m_id);
}

std::string const	&Player::get_login(void) const
{
  return (m_login);
}

File const	&Player::get_sound(void) const
{
  return (m_sound);
}

File const	&Player::get_sprite(void) const
{
  return (m_sprite);
}

void	Player::set_input(IUDP_protocol::Input const &input)
{
  m_input = input;
}
