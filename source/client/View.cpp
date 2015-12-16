//
// View.cpp for View in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Tue Nov 17 12:26:59 2015 Anthony Bury
// Last update Wed Dec  9 16:56:31 2015 Kevin Costa
//

#include "View.hpp"

View::View(void) :
  video(800, 600)
{
}

View::~View(void)
{
}

bool View::init(void)
{
  this->create(this->video, "R-Type", sf::Style::Titlebar | sf::Style::Close);
  return (true);
}

void View::loop(void)
{
  sf::Font font;
  sf::Text text;
  sf::Texture texture;

/*  font.loadFromFile("font/arial.ttf");
  text.setString("hello");
  text.setFont(font);
  text.setCharacterSize(30);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::Blue);
  toto.setFillColor(sf::Color::Green);*/
//  this->clear();
	while (this->isOpen())
	{
		this->clear();
		this->display();
    }
}
