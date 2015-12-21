//
// Core.hpp for Core in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:43:00 2015 Kevin Costa
// Last update Wed Dec  9 16:57:19 2015 Kevin Costa
//

#ifndef		VIEW_HPP_
# define	VIEW_HPP_

# include	<SFML/Graphics.hpp>
# include	<SFML/Window.hpp>

# include "Controller.hpp"

class View : public sf::RenderWindow
{
 private:
	sf::VideoMode video;
	sf::Event event;
	Model m_model;
	Controller m_control;

public:
  View(void);
  ~View(void);

public:
	void handleEvent(void);
  bool init(void);
	void aff(void);
  void loop(void);
};

#endif		/* !VIEW_HPP_ */
