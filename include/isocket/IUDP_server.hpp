//
// IUDP_server.hpp for IUDP_server in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:00:20 2015 Antoine Plaskowski
// Last update Fri Nov 20 05:15:53 2015 Antoine Plaskowski
//

#ifndef		IUDP_SERVER_HPP_
# define	IUDP_SERVER_HPP_

# include	<cstdint>
# include	"ASocket.hpp"

class	IUDP_server : public ASocket
{
public:
  virtual	~IUDP_server(void);
  virtual uintmax_t	recvfrom(uint8_t &data, uintmax_t &size, std::string &client) const;
  virtual uintmax_t	sendto(uint8_t const &data, uintmax_t &size, std::string const &client) const;  
};

#endif		/* !IUDP_SERVER_HPP_ */
