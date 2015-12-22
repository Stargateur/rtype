#ifndef		SPRITE_HPP_
# define	SPRITE_HPP_

# include "AElement.hpp"

class Sprite : public AElement, public sf::Sprite
{
public:
  Sprite(int pos_x, int pos_y);
  ~Sprite();

public:
	void update(const sf::Event &, Model &);
	void aff(View *);
};

#endif
