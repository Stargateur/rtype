//
// IStandard.hpp for IStandard in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:34:15 2015 Antoine Plaskowski
// Last update Fri Nov 20 06:22:30 2015 Antoine Plaskowski
//

#ifndef		ISTANDARD_HPP_
# define	ISTANDARD_HPP_

# include	<cstdint>
# include	"ASocket.hpp"

class	IStandard : public ASocket
{
public:
  enum	io : uint8_t
  {
    In,
    Out,
    Err
  };
public:
  IStandard(int fd);
  virtual	~IStandard(void);
  virtual uintmax_t	read(uint8_t &data, uintmax_t size) const = 0;
  virtual uintmax_t	write(uint8_t const &data, uintmax_t size) const = 0;
};

#endif		/* !ISTANDARD_HPP_ */
