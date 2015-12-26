//
// Text.cpp for  in /home/degand_a/Projects/rtype/source/client
// 
// Made by Alaric Degand
// Login   <degand_a@epitech.eu>
// 
// Started on  Sat Dec 26 23:33:11 2015 Alaric Degand
// Last update Sun Dec 27 00:04:58 2015 Alaric Degand
//

#include "View.hpp"
#include "Text.hpp"

Text::Text(std::string const &txt, sf::Font const &thefont) : AElement(TEXT, "")/*, sf::Text(txt, thefont)*/
{
  //setCharacterSize(30);
  //setStyle(sf::Text::Bold);
  //setColor(sf::Color::Red);
  //setFont(thefont);
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
