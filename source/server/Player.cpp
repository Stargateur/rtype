//
// Player.cpp for Player in /home/plasko_a/projet/cplusplus/rtype/source/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Dec 23 17:18:36 2015 Antoine Plaskowski
// Last update Sun Dec 27 09:24:06 2015 Antoine Plaskowski
//

#include	"Player.hpp"

Player::Player(File const &sprite, File const &sound, std::string const &login, uintmax_t id, uintmax_t team, uintmax_t x, uintmax_t y, uintmax_t size_x, uintmax_t size_y) :
  IEntite(),
  m_id(id),
  m_sprite(sprite),
  m_sound(sound),
  m_login(login),
  m_team(team),
  m_property(std::make_tuple(x, y, 10, 10)),
  m_size_x(size_x),
  m_size_y(size_y),
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

std::tuple<intmax_t, intmax_t, uintmax_t, uintmax_t> const	&Player::get_property(void) const
{
  return (m_property);
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
