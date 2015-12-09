//
// ICore.hpp for ICore in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:43:28 2015 Kevin Costa
// Last update Wed Dec  9 14:43:52 2015 Kevin Costa
//

#ifndef		ICORE_HPP_
# define	ICORE_HPP_

# include	<SFML/Graphics.hpp>
# include	<SFML/Window.hpp>

class ICore : public sf::RenderWindow
{
public:
  virtual ~ICore(void);

public:
  virtual bool init(void) = 0;
  virtual void loop(void) = 0;
};

#endif		/* !ICORE_HPP_ */
