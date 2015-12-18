/*
** Button.hpp for Button in /home/tacite_d/TEK3/rtype/include/client
** 
** Made by tacite_d
** Login   <tacite_d@Akagouan>
** 
** Started on  Thu Dec 10 17:36:16 2015 tacite_d
** Last update Thu Dec 10 17:36:16 2015 tacite_d
*/

#ifndef Button_HPP_
# define Button_HPP_

# include	<SFML/Graphics.hpp>
# include	<SFML/Window.hpp>
# include	<iostream>
# include	<string>

# include	"AElement.hpp"

class Button : public sf::RectangleShape, public AElement
{
private:
	std::string	_name;
	sf::Texture _pressedT;
	sf::Texture _unpressedT;
public:
	Button(float, float, float, float, std::string const&);
	~Button();
	void		update();
	void		eventFct(sf::Vector2i);

};

#endif /* !Button_HPP_ */
