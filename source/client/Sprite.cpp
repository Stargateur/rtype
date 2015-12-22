#include "View.hpp"
#include "Sprite.hpp"

Sprite::Sprite(int pos_x, int pos_y) : AElement(SPRITE, ""), sf::Sprite()
{
  this->text.loadFromFile("./font/vol.png");
  this->setTexture(text);
  this->setTextureRect(sf::IntRect(10, 10, 70, 68));
  this->setPosition(pos_x, pos_y);
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
