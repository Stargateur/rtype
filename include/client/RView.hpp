//
// View.hpp for View in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 15:31:59 2015 Kevin Costa
// Last update Wed Dec  9 16:28:28 2015 Kevin Costa
//

#ifndef		RVIEW_HPP_
# define	RVIEW_HPP_

#include	<SFML/Graphics.hpp>
#include	<vector>
#include 	"RButton.hpp"

class RView
{
private:
	//std::vector<RSprites *> _lstSprites;
	std::vector<RButton *> _lstButton;
	//std:vector<RText *> _lstText;
public:
  RView(void);
  ~RView(void);
  void		HandleEvent(sf::Vector2i);
  void		addRButton(RButton *);
  std::vector<RButton *>	getLstButton() const;

};

#endif		/* !RVIEW_HPP_ */
