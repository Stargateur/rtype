//
// IEntite.hpp for IEntite in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Dec 10 16:18:33 2015 Antoine Plaskowski
// Last update Thu Dec 24 11:08:08 2015 Antoine Plaskowski
//

#ifndef		IENTITE_HPP_
# define	IENTITE_HPP_

class	IEntite;

# include	<tuple>
# include	<list>
# include	<cstdint>
# include	"IGame.hpp"
# include	"ITime.hpp"
# include	"File.hpp"

class	IEntite
{
public:
  IEntite(void);
  IEntite(IEntite const &ientite);
  virtual ~IEntite(void);
  IEntite	&operator=(IEntite const &ientite);
  virtual void	run(std::list<IEntite *> const &ientites, std::list<IEntite *> &new_ientites,
		    ITime const &time_elapsed, ITime &time_callback) = 0;
  virtual void	domage(uintmax_t value) = 0;
  virtual void	colide(void) = 0;
  virtual std::tuple<uintmax_t, uintmax_t, uintmax_t, uintmax_t> const	&get_property(void) const = 0;
  virtual uintmax_t	get_team(void) const = 0;
  virtual File const	&get_sound(void) const = 0;
  virtual File const	&get_sprite(void) const = 0;
  virtual bool		check_colide(std::list<IEntite *> const &ientites) const = 0;
};

extern "C"
{
# define	NAME_FCT_NEW_IENTITE	"new_ientite"
# ifdef	__linux__
  IEntite	*new_ientite(std::list<IEntite *> const &ientites, uintmax_t team, uintmax_t x_max, uintmax_t y_max);
# else
  __declspec(dllexport) IEntite	*new_ientite(std::list<IEntite *> const &ientites, uintmax_t team, uintmax_t x_max, uintmax_t y_max);
# endif
  typedef IEntite	*(*fct_new_ientite)(std::list<IEntite *> const &ientites, uintmax_t team, uintmax_t x_max, uintmax_t y_max);
  typedef IEntite	*(&ref_new_ientite)(std::list<IEntite *> const &ientites, uintmax_t team, uintmax_t x_max, uintmax_t y_max);
}


#endif		/* !IENTITE_HPP_ */
