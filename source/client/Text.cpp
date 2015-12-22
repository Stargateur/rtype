#include "View.hpp"
#include "Text.hpp"

Text::Text() : AElement(TEXT, "")
{
}


Text::~Text()
{
}

void Text::update(const sf::Event &e, Model &m)
{
}

void Text::aff(View *view)
{
	view->draw(*this);
}
