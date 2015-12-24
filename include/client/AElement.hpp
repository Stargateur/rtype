#ifndef		AELEMENT_HPP_
# define	AELEMENT_HPP_

# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>

class View;
class Model;

typedef enum e_id
{
	BUTTON = 1,
	TEXT = 2,
	SPRITE = 3
} ID;

class AElement
{
	int m_id;
	std::string m_name;

public:
	AElement(int, const std::string &);
	~AElement(void);

public:
	void setId(int);
	int getId(void) const;
	virtual void update(const sf::Event &, Model &, sf::Vector2f &) = 0;
	const std::string &getName(void) const;
	virtual void aff(View *) = 0;
};

#endif
