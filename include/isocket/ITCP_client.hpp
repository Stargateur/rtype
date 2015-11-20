//
// ITCP_client.hpp for ITCP_client in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:18:04 2015 Antoine Plaskowski
// Last update Fri Nov 20 06:49:36 2015 Antoine Plaskowski
//

#ifndef		ITCP_CLIENT_HPP_
# define	ITCP_CLIENT_HPP_

# include	<cstdint>
# include	<string>
# include	"ASocket.hpp"

class	ITCP_client : public ASocket
{
public:
  ITCP_client(int fd);
  virtual ~ITCP_client(void);
  virtual uintmax_t	recv(uint8_t &data, uintmax_t size) const = 0;
  virtual uintmax_t	send(uint8_t const &data, uintmax_t size) const = 0;
  virtual std::string const	&get_host(void) const = 0;
};

#endif		/* !ITCP_CLIENT_HPP_ */
