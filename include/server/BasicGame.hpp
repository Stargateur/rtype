//
// BasicGame.hpp for BasicGame in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 10:12:30 2015 Alaric Degand
// Last update Tue Dec 22 11:48:10 2015 Alaric Degand
//

#ifndef		BASICGAME_HPP_
# define	BASICGAME_HPP_

#include	"IGame.hpp"

class		BasicGame: public IGame
{
  bool		_GameEnd;
public:
  BasicGame();
  ~BasicGame();
  virtual void		loop();
};

#endif		/* !BASICGAME_HPP_ */
