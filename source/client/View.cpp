//
// View.cpp for View in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Tue Nov 17 12:26:59 2015 Anthony Bury
// Last update Tue Nov 17 17:53:05 2015 Anthony Bury
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

void View::checkEvents(void)
{
  if (this->event.type == sf::Event::Closed)
    this->close();
  if (this->event.type == sf::Event::KeyPressed)
    if (this->event.key.code == sf::Keyboard::Escape)
      this->close();
}

void View::loop(void)
{
  sf::Font font;

  font.loadFromFile("font/arial.ttf");
  this->clear();
  while (this->isOpen())
    {
      sf::Text text("hello", font);
      text.setCharacterSize(30);
      text.setStyle(sf::Text::Bold);
      text.setColor(sf::Color::Red);
      this->draw(text);
      this->display();
      if (this->waitEvent(this->event))
	  this->checkEvents();
    }
}
