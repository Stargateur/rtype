/*
** Button.cpp for Button in /home/tacite_d/TEK3/rtype/source/client
** 
** Made by tacite_d
** Login   <tacite_d@Akagouan>
** 
** Started on  Thu Dec 10 17:35:58 2015 tacite_d
** Last update Thu Dec 10 17:35:59 2015 tacite_d
*/

#include	"View.hpp"
#include	"Button.hpp"


Button::Button(float x, float y, float longu, float larg, std::string const& name, void (*ptrs)(Model &)) : AElement(BUTTON, name)
{
	this->setSize(sf::Vector2f(longu, larg));
	this->setPosition(x, y);
	this->m_text = NULL;
	this->m_ptr = ptrs;
//	createPtr(type);
}


Button::~Button()
{
}

void Button::update(const sf::Event &e, Model &m, sf::Vector2i pos)
{
	float x, y;
	x = pos.x;
	y = pos.y;

	if (this->getGlobalBounds().contains(x, y))
	{
	if (this->m_ptr != NULL)
		(this->m_ptr)(m);
	}

	if (e.type == sf::Event::EventType::TextEntered)
		this->m_text->update(e, m);
}

void	Button::aff(View *view)
{
	view->draw(*this);
	if (this->m_text != NULL)
		this->m_text->aff(view);
}

void Button::setText(Text *text)
{
	this->m_text = text;
}

Text *Button::getText(void) const
{
	return (this->m_text);
}

void Button::chargeConnect(Model &model)
{
	model.setState(Model::CONNEXION);
	std::cout << "new state = connexion" << std::endl;
}

void Button::chargePrincip(Model &model)
{
	model.setState(Model::PRINCIPAL);
	std::cout << "new state = principal" << std::endl;
}

void Button::chargeParam(Model &model)
{
	model.setState(Model::PARAMS);
	std::cout << "new state = param" << std::endl;
}

void Button::chargeList(Model &model)
{
	model.setState(Model::LIST);
	std::cout << "new state = list" << std::endl;
}

void Button::chargeGame(Model &model)
{
	model.setState(Model::GAME);
	std::cerr << "new state = game" << std::endl;
}

void Button::createPtr(buttonType type)
{
	switch (type)
	{
	case CONNECT:
		this->m_ptr = &Button::chargeConnect;
	case PRINCIP:
		this->m_ptr = &Button::chargePrincip;
	case PARAM:
		this->m_ptr = &Button::chargeParam;
	case LIST:
		this->m_ptr = &Button::chargeList;
	case GAME:
		this->m_ptr = &Button::chargeGame;
	default:
		break;
	}
}