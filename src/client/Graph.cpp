//
// Graph.cpp for Graph in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Tue Nov 17 12:26:59 2015 Anthony Bury
// Last update Tue Nov 17 16:11:19 2015 Anthony Bury
//

#include "Graph.hpp"

Graph::Graph(void) :
  video(800, 600)
{
}

Graph::~Graph(void)
{

}

bool Graph::init(void)
{
  this->create(this->video, "R-Type", sf::Style::Titlebar | sf::Style::Close);
  return (true);
}

void Graph::checkEvents(void)
{
  if (this->event.type == sf::Event::Closed)
    this->close();
  if (this->event.type == sf::Event::KeyPressed)
    if (this->event.key.code == sf::Keyboard::Escape)
      this->close();
}

void Graph::loop(void)
{
  sf::Font font;

  font.loadFromFile("font/arial.ttf");
  while (this->isOpen())
    {
      while (this->pollEvent(this->event))
	  this->checkEvents();
      this->clear();
      sf::Text text("hello", font);
      text.setCharacterSize(30);
      text.setStyle(sf::Text::Bold);
      text.setColor(sf::Color::Red);
      this->draw(text);
      this->display();
    }
}
