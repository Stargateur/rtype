#include "View.hpp"
#include "Sprite.hpp"

Sprite::Sprite(int pos_x, int pos_y, const std::string &texture, const std::string &name) : AElement(SPRITE, name), sf::Sprite()
{
  this->text.loadFromFile(texture);
  this->setTexture(text);
  this->setTextureRect(sf::IntRect(10, 10, 70, 68));
  this->setPosition(pos_x, pos_y);
}


Sprite::~Sprite()
{
}

void Sprite::update(const sf::Event &e, Model &m, sf::Vector2i)
{
}

void Sprite::aff(View *view)
{
	view->draw(*this);
}
