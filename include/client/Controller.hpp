//
// Controller.hpp for Controller in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:36:20 2015 Kevin Costa
// Last update Wed Dec 16 16:53:50 2015 Kevin Costa
//

#ifndef		CONTROLLER_HPP_
# define	CONTROLLER_HPP_

# include	<SFML/Window.hpp>

# include	"Model.hpp"

class Controller
{
public:
  Controller(void);
  ~Controller(void);
  void update(sf::Event &event, Model &model, sf::Vector2i);
};

#endif		/* !CONTROLLER_HPP_ */
