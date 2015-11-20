//
// ASocket.hpp for ASocket in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 04:46:57 2015 Antoine Plaskowski
// Last update Fri Nov 20 06:11:52 2015 Antoine Plaskowski
//

#ifndef		ASOCKET_HPP_
# define	ASOCKET_HPP_

# include	"ISocket.hpp"
# include	"ITime.hpp"
# include	"sys/select.h"

class	ASocket : public ISocket
{
public:
  ASocket(int fd);
  virtual	~ASocket(void);
  static void	select(ITime const *timeout = nullptr);
  bool	can_read(void) const;
  bool	can_write(void) const;
  bool	want_read(void) const;
  bool	want_write(void) const;
  int	get_fd(void) const;
protected:
  int const	m_fd;
private:
  static fd_set	m_readfds;
  static fd_set	m_writefds;
  static int	m_nfds;
};

#endif		/* !ASOCKET_HPP_ */
