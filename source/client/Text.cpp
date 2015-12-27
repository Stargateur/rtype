//
// Text.cpp for  in /home/degand_a/Projects/rtype/source/client
// 
// Made by Alaric Degand
// Login   <degand_a@epitech.eu>
// 
// Started on  Sat Dec 26 23:33:11 2015 Alaric Degand
// Last update Sun Dec 27 13:47:04 2015 Alaric Degand
//

#include "View.hpp"
#include "Text.hpp"

Text::Text(float pos_x, float pos_y, const std::string &name, std::string const &txt, sf::Font const &thefont) : AElement(TEXT, name, false), sf::Text(txt, thefont, 35)
{
  this->setPosition(pos_x, pos_y);
  //setCharacterSize(30);
  //setStyle(sf::Text::Bold);
  setColor(sf::Color::Red);
  //setString(txt);
}


Text::~Text()
{
}

void Text::update(const sf::Event &e, Model &m, sf::Vector2f &)
{
}

void Text::aff(View *view)
{
	view->draw(*this);
}

std::string Text::getContent(void) const
{
  return (this->getString());
}

void		Text::setContent(std::string const &value)
{
  setString(value);
}

void            Text::eraseLast(void)
{

}
