//
// Sprite.hpp for  in /home/degand_a/Projects/rtype
// 
// Made by Alaric Degand
// Login   <degand_a@epitech.eu>
// 
// Started on  Fri Dec 25 16:35:10 2015 Alaric Degand
// Last update Fri Dec 25 17:10:17 2015 Alaric Degand
//

#ifndef		SPRITE_HPP_
# define	SPRITE_HPP_

# include "AElement.hpp"

class Sprite : public AElement, public sf::Sprite
{
  sf::Texture text;
public:
  Sprite(float pos_x, float pos_y, const std::string &texture, const std::string &name,
	 int spsize_x, int spsize_y, double size_x = 1,
	 double size_y = 1, int sprite_x = 0, int sprite_y = 0);
  ~Sprite();

public:
  void update(const sf::Event &, Model &, sf::Vector2f &);
  void aff(View *);
};

#endif
