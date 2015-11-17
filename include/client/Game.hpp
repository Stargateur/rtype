//
// Game.hpp for Game in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Tue Nov 17 12:21:06 2015 Anthony Bury
// Last update Tue Nov 17 13:11:40 2015 Anthony Bury
//

#ifndef		GAME_HPP_
# define	GAME_HPP_

# include	"Graph.hpp"

class Game
{
  IGraph *win;
  sf::Event event;

public:
  Game(void);
  ~Game(void);

public:
  bool init(void);
  void loop(void);
  void checkEvent(void);
};

#endif		/* !GAME_HPP_ */
