//
// IGame.hpp for IGame in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Dec 10 17:33:48 2015 Antoine Plaskowski
// Last update Tue Dec 22 12:01:57 2015 Alaric Degand
//

#ifndef		IGAME_HPP_
# define	IGAME_HPP_

class	IGame;

# include	"IEntite.hpp"

class	IGame
{
 public:
  IGame(/*IGame const &*/);
  virtual ~IGame(void);
  IGame	&operator=(IGame const &igame);
  virtual void	loop(void) = 0;
};

#endif		/* !IGAME_HPP_ */
