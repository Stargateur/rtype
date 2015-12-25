//
// Sprite.hpp for  in /home/degand_a/Projects/rtype
// 
// Made by Alaric Degand
// Login   <degand_a@epitech.eu>
// 
// Started on  Fri Dec 25 16:35:10 2015 Alaric Degand
// Last update Fri Dec 25 16:40:32 2015 Alaric Degand
//

#ifndef		SPRITE_HPP_
# define	SPRITE_HPP_

# include "AElement.hpp"

class Sprite : public AElement, public sf::Sprite
{
  sf::Texture text;
public:
  Sprite(float pos_x, float pos_y, const std::string &texture, const std::string &name, double size_x,
	 double size_y, int sprite_x = 0, int sprite_y = 0, int spsize_x = 0, int spsize_y = 0);
  ~Sprite();

public:
  void update(const sf::Event &, Model &, sf::Vector2f &);
  void aff(View *);
};

#endif
