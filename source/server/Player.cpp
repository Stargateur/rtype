//
// Player.cpp for Player in /home/plasko_a/projet/cplusplus/rtype/source/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Dec 23 17:18:36 2015 Antoine Plaskowski
// Last update Sun Dec 27 20:34:35 2015 Antoine Plaskowski
//

#include	"Time.hpp"
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
  m_vitesse(5),
  m_itime(*new Time())
{
}

Player::~Player(void)
{
  delete &m_itime;
}

void	Player::run(std::list<IEntite *> const &ientites, std::list<IEntite *> &new_ientites,
		    ITime const &time_elapsed, ITime &time_callback)
{
  m_itime += time_elapsed;
  if (m_hp == 0)
    throw std::exception();
  while (m_itime >= Time::second)
    {
      if (m_input.up)
	set_y(get_y() - m_vitesse);
      else if (m_input.down)
	set_y(get_y() + m_vitesse);
      if (m_input.left)
	set_x(get_x() - m_vitesse);
      else if (m_input.right)
	set_x(get_x() + m_vitesse);
      m_itime -= Time::second;
    }
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

void	Player::set_x(intmax_t x)
{
  if (x < 0)
    m_x = 0;
  else if (static_cast<uintmax_t>(x) > m_max_x)
    m_x = m_max_x;
  else
    m_x = x;
}

void	Player::set_y(intmax_t y)
{
  if (y < 0)
    m_y = 0;
  else if (static_cast<uintmax_t>(y) > m_max_y)
    m_y = m_max_y;
  else
    m_y = y;
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
