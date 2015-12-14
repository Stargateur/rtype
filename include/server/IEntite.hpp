//
// IEntite.hpp for IEntite in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Dec 10 16:18:33 2015 Antoine Plaskowski
// Last update Thu Dec 10 17:37:32 2015 Antoine Plaskowski
//

#ifndef		IENTITE_HPP_
# define	IENTITE_HPP_

class	IEntite;

# include	"IGame.hpp"

class	IEntite
{
public:
  IEntite(IEntite const &ientite);
  virtual ~IEntite(void);
  IEntite	&operator=(IEntite const &ientite);
  virtual void	run(IGame &game) = 0;
};

#endif		/* !IENTITE_HPP_ */
