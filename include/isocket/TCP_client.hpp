//
// TCP_client.hpp for TCP_client in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:18:04 2015 Antoine Plaskowski
// Last update Fri Nov 20 07:49:33 2015 Antoine Plaskowski
//

#ifndef		TCP_CLIENT_HPP_
# define	TCP_CLIENT_HPP_

# include	<cstdint>
# include	<string>
# include	<sys/socket.h>
# include	<netdb.h>
# include	"ITCP_client.hpp"
# include	"ITCP_server.hpp"

class	TCP_client : public ITCP_client
{
public:
  TCP_client(std::string const &host, std::string const &port);
  TCP_client(ITCP_server const &server);
  ~TCP_client(void);
  uintmax_t	recv(uint8_t &data, uintmax_t size) const;
  uintmax_t	send(uint8_t const &data, uintmax_t size) const;
  std::string const	&get_host(void) const;
private:
  static int	aux_connect(struct addrinfo const *rp);
  static int	connect(std::string const &host, std::string const &port);
  static int	accept(ITCP_server const &server, std::string &host);
private:
  std::string	m_host;
};

#endif		/* !TCP_CLIENT_HPP_ */
