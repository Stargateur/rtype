#ifndef		SPRITE_HPP_
# define	SPRITE_HPP_

# include "AElement.hpp"

class Sprite : public AElement, public sf::Sprite
{
public:
	Sprite();
	~Sprite();

public:
	void update(const sf::Event &, Model &);
	void aff(View *);
};

#endif