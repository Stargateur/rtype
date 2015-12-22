//
// Sprite.hpp for Sprite in /home/plasko_a/projet/cplusplus/rtype/include
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Dec 22 23:15:52 2015 Antoine Plaskowski
// Last update Tue Dec 22 23:46:54 2015 Antoine Plaskowski
//

#ifndef		SPRITE_HPP_
# define	SPRITE_HPP_

# include	<string>
# include	<cstdint>

class	Sprite
{
public:
  Sprite(std::string const &path);
  ~Sprite(void);
  std::string const	&get_name(void) const;
  uint8_t const	*get_data(void) const;
  uintmax_t	get_size(void) const;
private:
  std::string const	m_name;
  uint8_t	*m_data;
  uintmax_t	m_size;
};

#endif		/* !SPRITE_HPP_ */
