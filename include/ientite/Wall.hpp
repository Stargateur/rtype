//
// Wall.hpp for Wall in /home/degand_a/Projects/rtype/source/server/Entity
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Wed Dec 23 11:04:40 2015 Alaric Degand
// Last update Thu Dec 24 03:43:13 2015 Antoine Plaskowski
//

#ifndef		WALL_HPP_
# define	WALL_HPP_

#include	"IEntite.hpp"

class		Wall : public IEntite
{
public:
  Wall(std::list<IEntite *> const &ientites, uintmax_t team, uintmax_t x_max, uintmax_t y_max);
  void	run(std::list<IEntite *> const &ientites, std::list<IEntite *> &new_ientites,
	    ITime const &time_elapsed, ITime &time_callback);
  void	domage(uintmax_t value);
  void	colide(void);
  std::tuple<uintmax_t, uintmax_t, uintmax_t, uintmax_t> const	&get_property(void) const;
  uintmax_t	get_team(void) const;
  File const	&get_sound(void) const;
  File const	&get_sprite(void) const;
  bool	check_colide(std::list<IEntite *> const &ientites) const;
private:
  static File const	_sprite;
  static File const	_sound;
  uintmax_t	_team;
  uintmax_t	_hp;
  std::tuple<uintmax_t, uintmax_t, uintmax_t, uintmax_t>	_property;
  ITime		*_delay;
};

#endif		/* !WALL_HPP_ */
