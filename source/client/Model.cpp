//
// Model.cpp for Model in /home/costa_b/rendu/rtype/source/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:29:32 2015 Kevin Costa
// Last update Sun Dec 27 00:04:29 2015 Alaric Degand
//

#include "Model.hpp"

Model::Model()
{
  std::vector<AElement *> connexion;
  std::vector<AElement *> principal;
  std::vector<AElement *> params;
  std::vector<AElement *> list;

  sf::Font      thefont;
  thefont.loadFromFile("font/HighVoltage.ttf");
  
  connexionbox = true;
  this->m_endExec = false;
  this->m_actual = CONNEXION;
  connexion.push_back(new Sprite(0, 0, "sprites/stars.jpg", "background", 1256, 836));
  connexion.push_back(new Button(150, 150, 500, 100, "TextBox", NULL));
  connexion.push_back(new Sprite(150, 350, "sprites/costa_b.jpg", "costa", 200, 100));
  connexion.push_back(new Sprite(150, 350, "sprites/costa_b2.png", "costa2", 200, 100));
  connexion.push_back(new Button(50, 50, 200, 100, "b1", &Button::chargeConnect));
  connexion.push_back(new Sprite(50, 50, "sprites/Connexion.png", "background", 200, 100));
  connexion.push_back(new Text("bonjour", thefont));
  
  // connexion.push_back(new Sprite(0, 0, "sprites/vol.png", "ship", 60, 68));
  // connexion.push_back(new Button(400, 50, 200, 100, "b2", &Button::chargeGame));
  // connexion.push_back(new Sprite(400, 50, "sprites/Game.png", "background", 200, 100));
  // connexion.push_back(new Button(50, 400, 200, 100, "b3", &Button::chargeList));
  this->m_elements[CONNEXION] = connexion;
  principal.push_back(new Sprite(0, 0, "sprites/stars.jpg", "background", 1256, 836));
  this->m_elements[PRINCIPAL] = principal;
  params.push_back(new Sprite(0, 0, "sprites/stars.jpg", "background", 1256, 836));
  this->m_elements[PARAMS] = params;
  list.push_back(new Sprite(0, 0, "sprites/stars.jpg", "background", 1256, 836));
  this->m_elements[LIST] = list;
  this->m_elements[GAME] = std::vector<AElement *>();
}

Model::~Model()
{
  for (std::map<State, std::vector<AElement *>>::iterator it = this->m_elements.begin(); it != this->m_elements.end(); ++it)
    for (size_t i = 0; i < it->second.size(); i++)
      delete (it->second[i]);
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
  std::cout << "NIQUEZ VOS MORTS" << std::endl;
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

void Model::updateData(void)
{

}

void Model::setEnd(const bool &e)
{
  this->m_endExec = e;
}

void Model::setState(State menu)
{
  this->m_actual = menu;
}

bool Model::getEnd(void) const
{
  return (this->m_endExec);
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
  return (NULL);
}
