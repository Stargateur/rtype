//
// Core.cpp for Core in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Tue Nov 17 12:26:59 2015 Anthony Bury
// Last update Wed Dec  9 14:46:25 2015 Kevin Costa
//

#include "Core.hpp"
#include <string>
#include <iostream>

Core::Core(void) :
  video(800, 600)
{
}

Core::~Core(void)
{
}

bool Core::init(void)
{
  this->create(this->video, "R-Type", sf::Style::Titlebar | sf::Style::Close);
  return (true);
}

void Core::checkEvents(void)
{
  if (this->event.type == sf::Event::Closed)
    this->close();
  if (this->event.type == sf::Event::KeyPressed)
    if (this->event.key.code == sf::Keyboard::Escape)
      this->close();
}

void Core::loop(void)
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
