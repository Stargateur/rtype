//
// Controller.cpp for Controller in /home/costa_b/rendu/rtype/source/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:31:05 2015 Kevin Costa
// Last update Sat Dec 26 14:02:16 2015 Alaric Degand
//

#include	"Controller.hpp"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void		Controller::update(sf::Event &event, Model &model, sf::Vector2f &pos)
{
  std::vector<AElement *> elements;

  elements = model.getButtonElements();
  //  std::cout << elements.size() << std::endl;
  for (size_t i = 0; i < elements.size(); i++)
    {
      switch (event.type)
	{
	case sf::Event::Closed:
    	  break;
	case sf::Event::MouseButtonPressed:
	  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	    {
	      if (elements[i]->getId() == BUTTON)
		elements[i]->update(event, model, pos);
	    }
    	case sf::Event::TextEntered || sf::Event::MouseButtonPressed:
	  //			std::cout << "event catch" << std::endl;
	  /*	  if (elements[i]->getId() == BUTTON)
		  elements[i]->update(event, model);*/
    	  break;
	default:
	  break;
	}
    }
  switch (event.type)
    {
    case sf::Event::KeyPressed:
      model.Game(event.key.code);
      break;
    case sf::Event::KeyReleased:
      break;
    default:
      break;
    }
}
