//
// TCP_client.hpp for TCP_client in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 05:18:04 2015 Antoine Plaskowski
// Last update Tue Dec  8 15:22:26 2015 Antoine Plaskowski
//

#ifndef		TCP_CLIENT_HPP_
# define	TCP_CLIENT_HPP_

# include	<cstdint>
# include	<string>
# include	<sys/socket.h>
# include	<netdb.h>
# include	"ITCP_client.hpp"
# include	"ITCP_server.hpp"

class	TCP_client : public ASocket, public ITCP_client
{
public:
  TCP_client(std::string const &host, std::string const &port);
  TCP_client(ITCP_server const &server);
  ~TCP_client(void);
  uintmax_t	recv(uint8_t &data, uintmax_t size) const;
  uintmax_t	send(uint8_t const &data, uintmax_t size) const;
  std::string const	&get_host(void) const;
private:
  TCP_client(std::pair<int const, std::string const> &fd_ip);
  static int	aux_connect(struct addrinfo const *rp);
  static int	connect(std::string const &host, std::string const &port);
  static std::pair<int const, std::string const>	&accept(ITCP_server const &server);
private:
  std::string const	m_host;
};

class	TCP_client_exception : public ITCP_client_exception
{
public:
  TCP_client_exception(char const *what);
  char const	*what(void) const noexcept;
private:
  char const	*m_what;
};

#endif		/* !TCP_CLIENT_HPP_ */
