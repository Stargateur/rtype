//
// Model.cpp for Model in /home/costa_b/rendu/rtype/source/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:29:32 2015 Kevin Costa
// Last update Wed Dec  9 14:30:04 2015 Kevin Costa
//

#include "Model.hpp"

Model::Model()
{
	std::vector<AElement *> tmp;

	this->m_actual = CONNEXION;
	tmp.push_back(new Button(50, 50, 200, 100, "b1", Button::chargeConnect));
	tmp.push_back(new Button(400, 50, 200, 100, "b2", Button::chargeGame));
	tmp.push_back(new Button(50, 400, 200, 100, "b3", Button::chargeList));
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

void Model::setState(State menu)
{
	this->m_actual = menu;
}