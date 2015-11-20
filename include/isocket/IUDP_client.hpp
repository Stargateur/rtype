//
// IUDP_client.hpp for IUDP_client in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 04:52:54 2015 Antoine Plaskowski
// Last update Fri Nov 20 06:16:13 2015 Antoine Plaskowski
//

#ifndef		IUDP_CLIENT_HPP_
# define	IUDP_CLIENT_HPP_

# include	<string>

class	IUDP_client
{
public:
  virtual	~IUDP_client(void);
  virtual std::string const	&get_host(void) const = 0;
};

#endif		/* !IUDP_CLIENT_HPP_ */
