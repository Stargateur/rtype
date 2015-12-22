/*
** Button.hpp for Button in /home/tacite_d/TEK3/rtype/include/client
** 
** Made by tacite_d
** Login   <tacite_d@Akagouan>
** 
** Started on  Thu Dec 10 17:36:16 2015 tacite_d
** Last update Thu Dec 10 17:36:16 2015 tacite_d
*/

#ifndef		BUTTON_HPP_
# define	BUTTON_HPP_

# include	<SFML/Graphics.hpp>
# include	<SFML/Window.hpp>
# include	<iostream>
# include	<string>

# include	"Text.hpp"

class Button : public AElement, public sf::RectangleShape
{
public:
	typedef void (*ptr)(Model &);
public:
	typedef enum e_buttonType
	{
		CONNECT,
		PRINCIP,
		PARAM,
		LIST,
		GAME,
		UNKNOWN
	} buttonType;
private:
	Text *m_text;
	ptr m_ptr;

public:
	Button(float, float, float, float, std::string const&, void (*ptrs)(Model &));
	~Button();

public:
	void update(const sf::Event &, Model &, sf::Vector2i pos);
	void aff(View *);
	void setText(Text *);
	Text *getText(void) const;

public:
	static void chargeConnect(Model &);
	static void chargePrincip(Model &);
	static void chargeParam(Model &);
	static void chargeList(Model &);
	static void chargeGame(Model &);
	
private:
	void createPtr(buttonType);
};

#endif /* !BUTTON_HPP_ */
