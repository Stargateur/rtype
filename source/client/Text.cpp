#include "View.hpp"
#include "Text.hpp"

Text::Text() : AElement(TEXT, "")
{
}


Text::~Text()
{
}

void Text::update(const sf::Event &e, Model &m, sf::Vector2f &)
{
}

void Text::aff(View *view)
{
	view->draw(*this);
}
