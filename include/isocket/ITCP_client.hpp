//
// ITCP_client.hpp for ITCP_client in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:18:04 2015 Antoine Plaskowski
// Last update Fri Nov 20 05:20:42 2015 Antoine Plaskowski
//

#ifndef		ITCP_CLIENT_HPP_
# define	ITCP_CLIENT_HPP_

# include	<cstdint>
# include	"APacket.hpp"

class	ITCP_client : public APacket
{
public:
  virtual uintmax_t	recv(uint8_t &data, uintmax_t size) const;
  virtual uintmax_t	send(uint8_t const &data, uintmax_t size) const;
  virtual std::string const	&get_host(void) const;
};

#endif		/* !ITCP_CLIENT_HPP_ */
