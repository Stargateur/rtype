#ifndef		SPRITE_HPP_
# define	SPRITE_HPP_

# include "AElement.hpp"

class Sprite : public AElement, public sf::Sprite
{
  sf::Texture text;
public:
  Sprite(int pos_x, int pos_y, const std::string &texture, const std::string &name);
  ~Sprite();

public:
  void update(const sf::Event &, Model &, sf::Vector2i);
	void aff(View *);
};

#endif
