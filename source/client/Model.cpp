//
// Model.cpp for Model in /home/costa_b/rendu/rtype/source/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:29:32 2015 Kevin Costa
// Last update Wed Dec 23 13:31:11 2015 Kevin Costa
//

#include "Model.hpp"

Model::Model()
{
	std::vector<AElement *> tmp;

	this->m_actual = CONNEXION;
	tmp.push_back(new Button(50, 50, 200, 100, "b1", Button::chargeConnect));
	tmp.push_back(new Button(400, 50, 200, 100, "b2", Button::chargeGame));
	tmp.push_back(new Button(50, 400, 200, 100, "b3", Button::chargeList));
	tmp.push_back(new Sprite(300, 50, "./sprites/r-typesheet42.gif", "billette", tmp));
	tmp.push_back(new Sprite(300, 150, "./sprites/r-typesheet42.gif", "billy", tmp));
	tmp.push_back(new Sprite(300, 250, "./sprites/r-typesheet42.gif", "bill", tmp));
	tmp.push_back(new Sprite(300, 350, "./sprites/r-typesheet42.gif", "billou", tmp));
	tmp.push_back(new Sprite(300, 450, "./sprites/r-typesheet42.gif", "pwet", tmp));
	this->m_elements[CONNEXION] = tmp;
//	tmp.clear();
	this->m_elements[PRINCIPAL] = tmp;
	this->m_elements[PARAMS] = tmp;
	this->m_elements[LIST] = tmp;
	this->m_elements[GAME] = tmp;
}

Model::~Model()
{
}

std::vector<AElement *> Model::getElements(void)
{
	return (this->m_elements[this->m_actual]);
}

std::vector<AElement*> Model::getButtonElements(void)
{
	std::vector<AElement *> tmp;

	for (size_t i = 0; i < this->m_elements[this->m_actual].size(); i++)
		if (this->m_elements[this->m_actual][i]->getId() == BUTTON)
			tmp.push_back(this->m_elements[this->m_actual][i]);
	return (tmp);
}

void Model::Game(sf::Keyboard::Key &code)
{
  if (this->m_actual == GAME)
    {
      if (code == sf::Keyboard::Escape)
	std::cout << "return" << std::endl;
      if (code == sf::Keyboard::Space)
	std::cout << "space" << std::endl;
      else if (code == sf::Keyboard::Up)
	std::cout << "up" << std::endl;
      else if (code == sf::Keyboard::Down)
	std::cout << "down" << std::endl;
      else if (code == sf::Keyboard::Left)
	std::cout << "left" << std::endl;
      else if (code == sf::Keyboard::Right)
	std::cout << "right" << std::endl;
    }
}

void Model::setState(State menu)
{
	this->m_actual = menu;
}

Model::State Model::getState(void) const
{
  return (this->m_actual);
}

AElement *Model::getElementByName(const std::string &name)
{
	for (size_t i = 0; i < this->m_elements[this->m_actual].size(); i++)
		if (this->m_elements[this->m_actual][i]->getName() == name)
			return (this->m_elements[this->m_actual][i]);
}
