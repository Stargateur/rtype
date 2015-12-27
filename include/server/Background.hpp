//
// Background.hpp for Background in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Dec 26 15:01:44 2015 Antoine Plaskowski
// Last update Sun Dec 27 13:33:10 2015 Antoine Plaskowski
//

#ifndef		BACKGROUND_HPP_
# define	BACKGROUND_HPP_

# include	"IEntite.hpp"
# include	"File.hpp"

class	Background : public IEntite
{
public:
  Background(uintmax_t id, uintmax_t team, uintmax_t max_x, uintmax_t max_y);
  ~Background(void);
  void	run(std::list<IEntite *> const &ientites, std::list<IEntite *> &new_ientites,
		    ITime const &time_elapsed, ITime &time_callback);
  void	domage(uintmax_t value);
  void	colide(void);
  
  intmax_t	get_x(void) const;
  intmax_t	get_y(void) const;
  uintmax_t	get_size_x(void) const;
  uintmax_t	get_size_y(void) const;
  uintmax_t	get_team(void) const;
  uintmax_t	get_id(void) const;
  File const	&get_sound(void) const;
  File const	&get_sprite(void) const;
private:
  uintmax_t const	m_id;
  uintmax_t const	m_team;
  uintmax_t const	m_x;
  uintmax_t const	m_y;
  uintmax_t const	m_max_x;
  uintmax_t const	m_max_y;
  std::tuple<intmax_t, intmax_t, uintmax_t, uintmax_t>        m_property;
};

#endif		/* !BACKGROUND_HPP_ */
