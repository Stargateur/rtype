/*
** RButton.hpp for RButton in /home/tacite_d/TEK3/rtype/include/client
** 
** Made by tacite_d
** Login   <tacite_d@Akagouan>
** 
** Started on  Thu Dec 10 17:36:16 2015 tacite_d
** Last update Thu Dec 10 17:36:16 2015 tacite_d
*/

#ifndef RBUTTON_HPP_
# define RBUTTON_HPP_

# include	<SFML/Graphics.hpp>
# include	<SFML/Window.hpp>
# include	<iostream>
# include	<string>

# include	"AElement.hpp"

class RButton : public sf::RectangleShape, public AElement
{
private:
	std::string	_name;
	sf::Texture _pressedT;
	sf::Texture _unpressedT;
public:
	RButton(float, float, float, float, std::string const&);
	~RButton();
	void		setPressedT(sf::Texture);
	void		setUnpressedT(sf::Texture);
	void		eventFct(sf::Vector2i);

};

#endif /* !RBUTTON_HPP_ */
