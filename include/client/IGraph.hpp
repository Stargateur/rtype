//
// IGraph.hpp for IGraph in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Tue Nov 17 12:24:01 2015 Anthony Bury
// Last update Tue Nov 17 16:09:06 2015 Anthony Bury
//

#ifndef		IGRAPH_HPP_
# define	IGRAPH_HPP_

# include	<SFML/Graphics.hpp>
# include	<SFML/Window.hpp>

class IGraph : public sf::RenderWindow
{
public:
  virtual ~IGraph(void);

public:
  virtual bool init(void) = 0;
  virtual void loop(void) = 0;
};

#endif		/* !IGRAPH_HPP_ */
