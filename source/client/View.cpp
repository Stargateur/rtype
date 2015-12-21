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

void	View::handleEvent(void)
{
	while (this->pollEvent(this->event))
		{
			if (this->event.type == sf::Event::Closed)
				this->close();
			if ((this->event.type == sf::Event::KeyPressed) && (this->event.key.code == sf::Keyboard::Escape))
				this->close();
			this->m_control.update(this->event, this->m_model);
		}
}

bool View::init(void)
{
  this->create(this->video, "R-Type", sf::Style::Titlebar | sf::Style::Close);
  return (true);
}

void View::aff(void)
{
	std::vector<AElement *> tmp = this->m_model.getElements();

	for (size_t i = 0; i < tmp.size(); i++)
		tmp[i]->aff(this);
}

void View::loop(void)
{
	while (this->isOpen())
		{
			this->clear();
			this->handleEvent();
			this->aff();
			this->display();
    }
}
