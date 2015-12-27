//
// Player.hpp for Player in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Dec 23 17:18:39 2015 Antoine Plaskowski
// Last update Sun Dec 27 13:47:25 2015 Antoine Plaskowski
//

#ifndef		PLAYER_HPP_
# define	PLAYER_HPP_

# include	"IUDP_protocol.hpp"
# include	"IEntite.hpp"
# include	"File.hpp"

class	Player : public IEntite
{
public:
  Player(File const &sprite, File const &sound, std::string const &login, uintmax_t id, uintmax_t team, intmax_t x, intmax_t y, uintmax_t size_x, uintmax_t size_y, uintmax_t max_x, uintmax_t max_y);
  void	run(std::list<IEntite *> const &ientites, std::list<IEntite *> &new_ientites,
	    ITime const &time_elapsed, ITime &time_callback);
  void	domage(uintmax_t value);
  void	colide(void);
  std::string const	&get_login(void) const;
  intmax_t	get_x(void) const;
  intmax_t	get_y(void) const;
  uintmax_t	get_size_x(void) const;
  uintmax_t	get_size_y(void) const;
  uintmax_t	get_team(void) const;
  uintmax_t	get_id(void) const;
  File const	&get_sound(void) const;
  File const	&get_sprite(void) const;
  void	set_input(IUDP_protocol::Input const &input);
private:
  uintmax_t const	m_id;
  File const	&m_sprite;
  File const	&m_sound;
  std::string const	m_login;
  uintmax_t const	m_team;
  intmax_t	m_x;
  intmax_t	m_y;
  uintmax_t const	m_size_x;
  uintmax_t const	m_size_y;
  uintmax_t const	m_max_x;
  uintmax_t const	m_max_y;
  IUDP_protocol::Input	m_input;
  uintmax_t	m_hp;
  uintmax_t	m_vitesse;
};

#endif		/* !PLAYER_HPP_ */
