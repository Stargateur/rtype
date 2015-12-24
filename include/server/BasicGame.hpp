//
// BasicGame.hpp for BasicGame in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 10:12:30 2015 Alaric Degand
// Last update Thu Dec 24 06:57:47 2015 Antoine Plaskowski
//

#ifndef		BASICGAME_HPP_
# define	BASICGAME_HPP_

# include	"IGame.hpp"

class		BasicGame: public IGame
{
public:
  BasicGame(void);
  ~BasicGame(void);
  void	run(void);
private:
  
};

#endif		/* !BASICGAME_HPP_ */
