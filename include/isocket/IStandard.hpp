//
// IStandard.hpp for IStandard in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:34:15 2015 Antoine Plaskowski
// Last update Fri Nov 20 05:36:38 2015 Antoine Plaskowski
//

#ifndef		ISTANDARD_HPP_
# define	ISTANDARD_HPP_

# include	<cstdint>
# include	"ASocket.hpp"

class	IStandard : public ASocket
{
public:
  virtual uintmax_t	read(uint8_t &data, uintmax_t size) const;
  virtual uintmax_t	write(uint8_t const &data, uintmax_t size) const;
};

#endif		/* !ISTANDARD_HPP_ */
