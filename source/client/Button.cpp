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

Button::Button(float x, float y, float longu, float larg, std::string const& name, void (Button::*ptr)(Model &)) : AElement(BUTTON, name)
{
	this->setSize(sf::Vector2f(longu, larg));
	this->setPosition(x, y);
	this->m_text = NULL;
	this->m_ptr = ptr;
}

Button::~Button()
{
}

void Button::update(const sf::Event &e, Model &m)
{
	if (e.type == sf::Event::EventType::TextEntered)
		this->m_text->update(e, m);
	else if (this->m_ptr != NULL)
		(this->*m_ptr)(m);
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
