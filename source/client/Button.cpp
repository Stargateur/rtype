/*
** Button.cpp for Button in /home/tacite_d/TEK3/rtype/source/client
** 
** Made by tacite_d
** Login   <tacite_d@Akagouan>
** 
** Started on  Thu Dec 10 17:35:58 2015 tacite_d
** Last update Thu Dec 10 17:35:59 2015 tacite_d
*/

#include	"Button.hpp"

Button::Button(float x, float y, float longu, float larg, std::string const& name) : AElement(BUTTON)
{
	this->_name = name;
	this->setSize(sf::Vector2f(longu, larg));
	this->setPosition(x, y);
}

Button::~Button()
{
}

void Button::update()
{
}

void	Button::eventFct(sf::Vector2i mouse_pos)
{
  	float x, y;

	x = mouse_pos.x;
  	y = mouse_pos.y;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))      	
    {
	  	if(this->getGlobalBounds().contains(x, y))
  			std::cout << "changement de texture : Bouton " << this->_name << " pressé" << std::endl;
  	}

}

void	Button::aff(View &view)
{
	view.draw(*this);
}