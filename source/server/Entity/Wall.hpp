//
// Wall.hpp for Wall in /home/degand_a/Projects/rtype/source/server/Entity
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Wed Dec 23 11:04:40 2015 Alaric Degand
// Last update Wed Dec 23 14:21:29 2015 Alaric Degand
//

#ifndef		WALL_HPP_
# define	WALL_HPP_

#include	"IEntite.hpp"

class		Wall : public IEntite
{
private:
  static const File	_sprite;
  static const File	_sound;
  uintmax_t	_team;
  uintmax_t	_life;
  std::tuple<uintmax_t, uintmax_t, uintmax_t, uintmax_t> _property;
  ITime		_delay;
public:
  Wall(std::list<IEntite *> const &ientites, uintmax_t x_max, uintmax_t y_max);
  virtual void	run(std::list<IEntite *> const &ientites, std::list<IEntite *> &new_ientites,
		    ITime const &time_elapsed, ITime &time_callback);
  virtual void	domage(uintmax_t value);
  virtual void	colide(void);
  virtual std::tuple<uintmax_t, uintmax_t, uintmax_t, uintmax_t> const	&get_property(void) const;
  virtual uintmax_t	get_team(void) const;
  virtual File const	&get_sound(void) const;
  virtual File const	&get_sprite(void) const;
  virtual bool		check_colide(std::list<IEntite *> const &ientites) const;
};

#endif		/* !WALL_HPP_ */
