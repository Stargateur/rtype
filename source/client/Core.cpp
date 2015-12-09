//
// Core.cpp for Core in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Tue Nov 17 12:26:59 2015 Anthony Bury
// Last update Wed Dec  9 16:56:31 2015 Kevin Costa
//

#include "Core.hpp"
#include <string>
#include <iostream>

Core::Core(void) :
  video(800, 600)
{
  this->window = new sf::RenderWindow();
}

Core::~Core(void)
{
}

bool Core::init(void)
{
  window->create(this->video, "R-Type", sf::Style::Titlebar | sf::Style::Close);
  return (true);
}

void Core::checkEvents(void)
{
  if (this->event.type == sf::Event::Closed)
    window->close();
  if (this->event.type == sf::Event::KeyPressed)
    if (this->event.key.code == sf::Keyboard::Escape)
      window->close();
}

void Core::loop(void)
{
  sf::Font font;
  sf::Text text;

  font.loadFromFile("font/arial.ttf");
  text.setString("hello");
  text.setFont(font);
  text.setCharacterSize(30);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::Red);
  window->clear();
  while (window->isOpen())
    {
      window->clear();
      window->draw(text);
      window->display();
      if (window->pollEvent(this->event))
	this->checkEvents();
    }
}

sf::RenderWindow *Core::getWindow()
{
  return (this->window);
}
