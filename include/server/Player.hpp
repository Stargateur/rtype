//
// Player.hpp for Player in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Dec 23 17:18:39 2015 Antoine Plaskowski
// Last update Sat Dec 26 15:16:53 2015 Antoine Plaskowski
//

#ifndef		PLAYER_HPP_
# define	PLAYER_HPP_

# include	"IUDP_protocol.hpp"
# include	"IEntite.hpp"

class	Player : public IEntite
{
public:
  Player(File const &sprite, File const &sound, std::string const &login, uintmax_t team, uintmax_t x, uintmax_t y, uintmax_t size_x, uintmax_t size_y);
  void	run(std::list<IEntite *> const &ientites, std::list<IEntite *> &new_ientites,
	    ITime const &time_elapsed, ITime &time_callback);
  void	domage(uintmax_t value);
  void	colide(void);
  std::tuple<uintmax_t, uintmax_t, uintmax_t, uintmax_t> const	&get_property(void) const;
  std::string const	&get_login(void) const;
  uintmax_t	get_team(void) const;
  File const	&get_sound(void) const;
  File const	&get_sprite(void) const;
  void	set_input(IUDP_protocol::Input const &input);
private:
  File const	&m_sprite;
  File const	&m_sound;
  std::string const	m_login;
  uintmax_t const	m_team;
  std::tuple<uintmax_t, uintmax_t, uintmax_t, uintmax_t>	m_property;
  uintmax_t	m_size_x;
  uintmax_t	m_size_y;
  IUDP_protocol::Input	m_input;
  uintmax_t	m_hp;
  uintmax_t	m_vitesse;
};

#endif		/* !PLAYER_HPP_ */
