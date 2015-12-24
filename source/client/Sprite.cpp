#include "View.hpp"
#include "Sprite.hpp"

Sprite::Sprite(float pos_x, float pos_y, const std::string &texture, const std::string &name, int sprite_x, int sprite_y, int spsize_x, int spsize_y, double size_x, double size_y) : AElement(SPRITE, name), sf::Sprite()
{
  this->text.loadFromFile(texture);
  this->setTexture(text);
  this->setTextureRect(sf::IntRect(sprite_x, sprite_y, spsize_x, spsize_y));
  this->setPosition(pos_x, pos_y);
  this->scale(sf::Vector2f(size_x, size_y));
}


Sprite::~Sprite()
{
}

void Sprite::update(const sf::Event &e, Model &m, sf::Vector2f &)
{
}

void Sprite::aff(View *view)
{
	view->draw(*this);
}
