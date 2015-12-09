//
// Core.hpp for Core in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:43:00 2015 Kevin Costa
// Last update Wed Dec  9 16:25:04 2015 Kevin Costa
//

#ifndef		CORE_HPP_
# define	CORE_HPP_

# include	"ICore.hpp"

class Core : public ICore
{
  sf::RenderWindow *window;
  sf::VideoMode video;
  sf::Event event;

public:
  Core(void);
  ~Core(void);

public:
  bool init(void);
  void loop(void);
  void checkEvents(void);
};

#endif		/* !CORE_HPP_ */
