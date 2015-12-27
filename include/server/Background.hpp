//
// Background.hpp for Background in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Dec 26 15:01:44 2015 Antoine Plaskowski
// Last update Sun Dec 27 07:56:26 2015 Antoine Plaskowski
//

#ifndef		BACKGROUND_HPP_
# define	BACKGROUND_HPP_

# include	"IEntite.hpp"

class	Background : public IEntite
{
public:
  Background(uintmax_t id, uintmax_t team, uintmax_t size_x, uintmax_t size_y);
  ~Background(void);
  void	run(std::list<IEntite *> const &ientites, std::list<IEntite *> &new_ientites,
		    ITime const &time_elapsed, ITime &time_callback);
  void	domage(uintmax_t value);
  void	colide(void);
  std::tuple<intmax_t, intmax_t, uintmax_t, uintmax_t> const	&get_property(void) const;
  uintmax_t	get_team(void) const;
  uintmax_t	get_id(void) const;
  File const	&get_sound(void) const;
  File const	&get_sprite(void) const;
private:
  uintmax_t const	m_id;
  uintmax_t const	m_team;
  std::tuple<intmax_t, intmax_t, uintmax_t, uintmax_t>        m_property;
};

#endif		/* !BACKGROUND_HPP_ */
