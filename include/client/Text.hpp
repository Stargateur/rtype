//
// Text.hpp for  in /home/degand_a/Projects/rtype/include/client
// 
// Made by Alaric Degand
// Login   <degand_a@epitech.eu>
// 
// Started on  Sat Dec 26 23:32:44 2015 Alaric Degand
// Last update Sun Dec 27 00:32:46 2015 Alaric Degand
//

#ifndef		TEXT_HPP_
# define	TEXT_HPP_

# include "AElement.hpp"

class Text : public AElement, public sf::Text
{
public:
  Text(float, float, std::string const &, sf::Font const &);
  ~Text();

public:
	void update(const sf::Event &, Model &, sf::Vector2f &);
	void aff(View *);
	const std::string &getContent(void) const;
};

#endif
