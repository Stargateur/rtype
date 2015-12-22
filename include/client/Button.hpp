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
private:
	Text *m_text;
	void (Button::*m_ptr)(Model &);

public:
	Button(float, float, float, float, std::string const&, void (Button::*ptr)(Model &) = NULL);
	~Button();

public:
	void update(const sf::Event &, Model &);
	void aff(View *);
	void setText(Text *);
	Text *getText(void) const;
};

#endif /* !BUTTON_HPP_ */
