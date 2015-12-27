/*
** Button.hpp for Button in /home/tacite_d/TEK3/rtype/include/client
** 
** Made by tacite_d
** Login   <tacite_d@Akagouan>
** 
** Started on  Thu Dec 10 17:36:16 2015 tacite_d
// Last update Sun Dec 27 15:43:24 2015 Alaric Degand
*/

#ifndef		BUTTON_HPP_
# define	BUTTON_HPP_

# include	<SFML/Graphics.hpp>
# include	<SFML/Window.hpp>
# include	<iostream>
# include	<string>

# include	"Text.hpp"

class Button;

typedef void (Button::*ptr)(Model &);

class Button : public AElement, public sf::RectangleShape
{
//public:
//	typedef enum e_buttonType
//	{
//		CONNECT,
//		PRINCIP,
//		PARAM,
//		LIST,
//		GAME,
//		UNKNOWN
//	} buttonType; WHAT?
private:
  Text *m_text;
  ptr m_ptr;
  std::string m_line;
  
public:
  Button(float, float, float, float, std::string const&, const bool &, ptr, sf::Font const &thefont, std::string const & = "");
  ~Button();

public:
  void update(const sf::Event &, Model &, sf::Vector2f &);
  void aff(View *);
  void setText(Text *);
  Text *getText(void) const;
  std::string getContent(void) const;
  void setContent(std::string const &);
  void	eraseLast(void);

public:
  void chargeConnect(Model &);
  void chargePrincip(Model &);
  void chargeParam(Model &);
  void chargeList(Model &);
  void chargeGame(Model &);
  void focused(Model &);
	
//private:
//	void createPtr(buttonType);
};

#endif /* !BUTTON_HPP_ */
