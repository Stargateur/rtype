#ifndef		TEXT_HPP_
# define	TEXT_HPP_

# include "AElement.hpp"

class Text : public AElement, public sf::Text
{
public:
	Text();
	~Text();

public:
	void update(const sf::Event &, Model &);
	void aff(View *);
};

#endif