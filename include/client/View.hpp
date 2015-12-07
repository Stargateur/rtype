//
// Graph.hpp for Graph in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Tue Nov 17 12:26:13 2015 Anthony Bury
// Last update Tue Nov 17 16:11:06 2015 Anthony Bury
//

#ifndef		VIEW_HPP_
# define	VIEW_HPP_

# include	"IView.hpp"

class View : public IView
{
  sf::VideoMode video;
  sf::Event event;

public:
  View(void);
  ~View(void);

public:
  bool init(void);
  void loop(void);
  void checkEvents(void);
};

#endif		/* !GRAPH_HPP_ */
