//
// Controller.cpp for Controller in /home/costa_b/rendu/rtype/source/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:31:05 2015 Kevin Costa
// Last update Mon Dec 21 14:35:44 2015 Anthony Bury
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

  elements = model.getButtonElements();
  for (size_t i = 0; i < elements.size(); i++)
    {
      switch (event.type)
	{
	case sf::Event::Closed:
    	  break;
    	case sf::Event::TextEntered || sf::Event::MouseButtonPressed:
	  if (elements[i]->getId() == BUTTON)
	    elements[i]->update(event, model);
    	  break;
    	case sf::Event::KeyPressed:
	  break;
    	case sf::Event::KeyReleased:
	  break;
	default:
	  break;
	}
    }
}

