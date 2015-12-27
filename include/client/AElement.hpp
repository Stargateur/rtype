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
	bool m_canFocus;
	bool m_isFocus;

public:
	AElement(int, const std::string &, const bool &);
	~AElement(void);

public:
	int getId(void) const;
	bool isFocus(void) const;
	const std::string &getName(void) const;
	virtual void update(const sf::Event &, Model &, sf::Vector2f &) = 0;
	virtual void aff(View *) = 0;
	virtual std::string getContent(void) const = 0;

protected:
	void setId(int);
	void setFocus(const bool &);
};

#endif
