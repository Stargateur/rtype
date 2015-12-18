#pragma once

#include <SFML/Graphics.hpp>

#include "AElement.hpp"

class Sprite : public AElement, public sf::Sprite
{
public:
	Sprite();
	~Sprite();
};
