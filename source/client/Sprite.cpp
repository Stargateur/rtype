#include "View.hpp"
#include "Sprite.hpp"

Sprite::Sprite(int pos_x, int pos_y, const std::string &texture, const std::string &name, std::vector<AElement *> tmp) : AElement(SPRITE, name), sf::Sprite()
{
  for (size_t i = 0; i < tmp.size(); i++)
    {
      if (tmp[i]->getId() == SPRITE)
	this->sprite_y += 17;
    }
  this->text.loadFromFile(texture);
  this->setTexture(text);
  this->setTextureRect(sf::IntRect(this->sprite_x, this->sprite_y, 32, 18));
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
