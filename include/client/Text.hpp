//
// Text.hpp for  in /home/degand_a/Projects/rtype/include/client
// 
// Made by Alaric Degand
// Login   <degand_a@epitech.eu>
// 
// Started on  Sat Dec 26 23:32:44 2015 Alaric Degand
// Last update Sun Dec 27 13:44:47 2015 Alaric Degand
//

#ifndef		TEXT_HPP_
# define	TEXT_HPP_

# include "AElement.hpp"

class Text : public AElement, public sf::Text
{
public:
  Text(float, float, const std::string &, std::string const &, sf::Font const &);
  ~Text();

public:
	void update(const sf::Event &, Model &, sf::Vector2f &);
	void aff(View *);
	std::string getContent(void) const;
  void setContent(std::string const &);
  void eraseLast(void);
};

#endif
