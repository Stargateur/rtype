//
// TCP_client.hpp for TCP_client in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:18:04 2015 Antoine Plaskowski
// Last update Fri Nov 20 05:31:58 2015 Antoine Plaskowski
//

#ifndef		TCP_CLIENT_HPP_
# define	TCP_CLIENT_HPP_

# include	<cstdint>
# include	"ITCP_client.hpp"

class	TCP_client : public ITCP_client
{
public:
  TCP_client(std::string const &host, std::string const &port);
  TCP_client(ITCP_server const &server);
  uintmax_t	recv(uint8_t &data, uintmax_t size) const;
  uintmax_t	send(uint8_t const &data, uintmax_t size) const;
  std::string const	&get_host(void) const;
private:
  std::string const	m_host;
};

#endif		/* !TCP_CLIENT_HPP_ */
