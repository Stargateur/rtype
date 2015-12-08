//
// IUDP_client.hpp for IUDP_client in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 04:58:06 2015 Antoine Plaskowski
// Last update Tue Dec  8 15:17:54 2015 Antoine Plaskowski
//

#ifndef		UDP_CLIENT_HPP_
# define	UDP_CLIENT_HPP_

# include	<arpa/inet.h>
# include	<sys/socket.h>
# include	<tuple>
# include	"IUDP_client.hpp"
# include	"ASocket.hpp"

class	UDP_client : public IUDP_client, public ASocket
{
public:
  UDP_client(std::string const &host, std::string const &port);
  std::string const	&get_host(void) const;
  uintmax_t	send(uint8_t const &data, uintmax_t size) const;
  uintmax_t	recv(uint8_t &data, uintmax_t size) const;
private:
  static int    aux_connect(struct addrinfo const *rp);
  static int    connect(std::string const &host, std::string const &port);
  std::string const	m_host;
};

class	UDP_client_exception : public IUDP_client_exception
{
public:
  UDP_client_exception(char const *what);
  char const	*what(void) const noexcept;
private:
  char const	*m_what;
};

#endif		/* !UDP_CLIENT_HPP_ */
