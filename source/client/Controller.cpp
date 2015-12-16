//
// Controller.cpp for Controller in /home/costa_b/rendu/rtype/source/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:31:05 2015 Kevin Costa
// Last update Wed Dec 16 17:12:19 2015 Kevin Costa
//

#include	"Controller.hpp"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void		Controller::update(sf::Event &event, Model &model)
{
  std::vector<AElement *> elements;

  elements = model.getElements();
  for (size_t i = 0; i < elements.size(); i++)
    {
      switch (event.type)
	{
	case sf::Event::Closed:
	  break;
	case sf::Event::TextEntered:
	  break;
	case sf::Event::KeyPressed:
	  break;
	case sf::Event::KeyReleased:
	  break;
	case sf::Event::MouseButtonPressed:
	  break;
	}
    }
}

