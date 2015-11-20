//
// IAddress.hpp for IAddress in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 04:52:54 2015 Antoine Plaskowski
// Last update Fri Nov 20 13:24:07 2015 Antoine Plaskowski
//

#ifndef		IADDRESS_HPP_
# define	IADDRESS_HPP_

# include	<string>
# include	<sys/socket.h>
# include	<arpa/inet.h>

class	IAddress
{
public:
  union	addr
  {
    sockaddr	base;
    sockaddr_in		ipv4;
    sockaddr_in6	ipv6;
  }     sockaddr;
public:
  virtual	~IAddress(void);
  virtual std::string const	&get_host(void) const = 0;
  virtual addr const	&get_addr(void) const = 0;
  virtual socklen_t	get_len(void) const = 0;
};

bool	operator==(IAddress const &left, IAddress const &right);

#endif		/* !IADDRESS_HPP_ */
