//
// ISocket.hpp for ISocket in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 04:45:20 2015 Antoine Plaskowski
// Last update Tue Dec  8 14:04:53 2015 Antoine Plaskowski
//

#ifndef		ISOCKET_HPP_
# define	ISOCKET_HPP_

class	ISocket
{
public:
  virtual	~ISocket(void);
  virtual int	get_fd(void) const = 0;
};

#endif		/* !ISOCKET_HPP_ */
