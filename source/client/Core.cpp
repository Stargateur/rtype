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
}

Core::~Core(void)
{
}

bool Core::init(void)
{
  this->create(this->video, "R-Type", sf::Style::Titlebar | sf::Style::Close);
  return (true);
}

void Core::checkEvents(RView *view)
{
	sf::Vector2i mouse_pos;

	mouse_pos = sf::Mouse::getPosition(*this);
	if (this->event.type == sf::Event::Closed)
		this->close();
	if (this->event.type == sf::Event::KeyPressed)
		if (this->event.key.code == sf::Keyboard::Escape)
			this->close();
	view->HandleEvent(mouse_pos);
}

void Core::loop(void)
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
      this->drawView();
      this->display();
     if (this->pollEvent(this->event))
		this->checkEvents(this->_currentView);
    }
}

void	Core::addView(RView *view)
{
	this->_lstView.push_back(view);
	if (this->_lstView.size() == 1)
		this->_currentView = view;
}

void	Core::drawView()
{
	for (size_t index = 0; index != this->_currentView->getLstButton().size(); ++index)
	{
		this->draw(*(this->_currentView->getLstButton()[index]));
	}
}
