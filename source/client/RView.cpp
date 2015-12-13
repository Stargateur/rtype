//
// View.cpp for View in /home/costa_b/rendu/rtype/source/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 15:31:00 2015 Kevin Costa
// Last update Wed Dec  9 15:31:26 2015 Kevin Costa
//

#include "RView.hpp"

RView::RView()
{
}

RView::~RView()
{
}

void	RView::addRButton(RButton *button)
{
	this->_lstButton.push_back(button);
}

void	RView::HandleEvent(sf::Vector2i mouse_pos)
{
	for (size_t index = 0; index != this->_lstButton.size(); ++ index)
	{
		this->_lstButton[index]->eventFct(mouse_pos);
	}
}

std::vector<RButton *>	RView::getLstButton() const
{
	return (this->_lstButton);
}
