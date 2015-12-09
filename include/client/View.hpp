//
// View.hpp for View in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 15:31:59 2015 Kevin Costa
// Last update Wed Dec  9 16:28:28 2015 Kevin Costa
//

#ifndef		VIEW_HPP_
# define	VIEW_HPP_

# include	"Core.hpp"
#include	<SFML/Window.hpp>

class View : public Core
{
public:
  View(void);
  ~View(void);
private:
  sf::RenderTexture texture;
};

#endif		/* !VIEW_HPP_ */
