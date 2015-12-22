#include "View.hpp"
#include "Sprite.hpp"

Sprite::Sprite() : AElement(SPRITE, "")
{
}


Sprite::~Sprite()
{
}

void Sprite::update(const sf::Event &e, Model &m)
{
}

void Sprite::aff(View *view)
{
	view->draw(*this);
}
