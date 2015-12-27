//
// Model.cpp for Model in /home/costa_b/rendu/rtype/source/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:29:32 2015 Kevin Costa
// Last update Sun Dec 27 14:12:40 2015 Alaric Degand
//

#include "Model.hpp"

Model::Model() :
	m_actual(CONNEXION), m_canConnect(false), m_endExec(false)
{
  std::vector<AElement *> connexion;
  std::vector<AElement *> principal;
  std::vector<AElement *> params;
  std::vector<AElement *> list;

  if (!m_font.loadFromFile("font/HighVoltage.ttf"))
    std::cout << "Font not loaded" << std::endl;
  
  connexionbox = true;
  connexion.push_back(new Sprite(0, 0, "sprites/stars.jpg", "background", 1256, 836));
  connexion.push_back(new Button(150, 150, 500, 50, "TEXT_LOGIN", true, &Button::focused, m_font));
  connexion.push_back(new Button(150, 210, 500, 50, "TEXT_PASSWORD", true, &Button::focused, m_font));
  connexion.push_back(new Button(150, 270, 500, 50, "TEXT_HOST", true, &Button::focused, m_font));
  connexion.push_back(new Button(150, 330, 500, 50, "TEXT_PORT", true, &Button::focused, m_font));
  connexion.push_back(new Sprite(50, 420, "sprites/costa_b.jpg", "costa", 200, 100));
  connexion.push_back(new Sprite(50, 420, "sprites/costa_b2.png", "costa2", 200, 100));
  connexion.push_back(new Button(50, 50, 200, 100, "b1", false, &Button::chargePrincip, m_font));
  connexion.push_back(new Sprite(50, 50, "sprites/Connexion.png", "background", 200, 100));
  connexion.push_back(new Text(251, 450, "Instruct", "Veuillez entrer votre\npseudo/passord/ip/port, puis appuyez sur \nconnexion", m_font));
  
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

void	Model::getPressed(sf::Keyboard::Key &code)
{
  if (m_actual == CONNEXION)
    {
      AElement	*tmp = getElementFocused();
      m_swap = char(code);

      if (tmp != NULL)
	{
	  if (code == 8)
	    tmp->eraseLast();
	  else
	    tmp->setContent(m_swap);
	}
      //std::cout << code << std::endl;
    }
}

void Model::updateData(void)
{

}

void Model::setEnd(const bool &end)
{
  this->m_endExec = end;
}

void Model::setState(State menu)
{
  this->m_actual = menu;
}

void Model::setConnect(const bool &connect)
{
	this->m_canConnect = connect;
}

bool Model::getEnd(void) const
{
  return (this->m_endExec);
}

bool Model::canConnect(void) const
{
	return (this->m_canConnect);
}

Model::State Model::getState(void) const
{
  return (this->m_actual);
}

bool Model::elementIsFocus(void)
{
  for (size_t i = 0; i < this->m_elements[this->m_actual].size(); i++)
    if (this->m_elements[this->m_actual][i]->isFocus())
      return (true);
  return (false);
}

AElement *Model::getElementByName(const std::string &name) const
{
  for (std::map<State, std::vector<AElement *>>::const_iterator it = this->m_elements.begin(); it != this->m_elements.end(); ++it)
    for (size_t i = 0; i < it->second.size(); i++)
      if (it->second[i]->getName() == name)
	return (it->second[i]);
  return (NULL);
}

AElement *Model::getElementFocused(void)
{
  for (size_t i = 0; i < this->m_elements[this->m_actual].size(); i++)
    if (this->m_elements[this->m_actual][i]->isFocus())
      return (this->m_elements[this->m_actual][i]);
  return (NULL);
}

bool	Model::getCosta() const
{
  return (costabouche);
}

void	Model::setCosta(bool value)
{
  costabouche = value;
}
