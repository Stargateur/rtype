#include "Sprite.hpp"

Sprite::Sprite() : AElement(SPRITE), sf::Sprite()
{
}


Sprite::~Sprite()
{
}

void Sprite::update()
{
}

void Sprite::aff(View &view)
{
	view.draw(*this);
}
