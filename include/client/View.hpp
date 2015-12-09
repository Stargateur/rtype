//
// View.hpp for View in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:33:09 2015 Kevin Costa
// Last update Wed Dec  9 14:33:23 2015 Kevin Costa
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

#endif		/* !View_HPP_ */
