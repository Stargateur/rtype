//
// UDP_client.hpp for UDP_client in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 04:58:06 2015 Antoine Plaskowski
// Last update Fri Nov 20 05:12:15 2015 Antoine Plaskowski
//

#ifndef		UDP_CLIENT_HPP_
# define	UDP_CLIENT_HPP_

# include	"IUPD_client.hpp"

class	UDP_client : public IUPD_client
{
public:
  UDP_client(std::string const &host);
  std::string const	&get_host(void) const;
private:
  std::string const	m_host;
};

#endif		/* !UDP_CLIENT_HPP_ */
