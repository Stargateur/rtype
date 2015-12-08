//
// Select.hpp for Select in /home/plasko_a/projet/cplusplus/rtype/include/isocket
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Dec  8 13:56:31 2015 Antoine Plaskowski
// Last update Tue Dec  8 14:23:13 2015 Antoine Plaskowski
//

#ifndef		SELECT_HPP_
# define	SELECT_HPP_

# include	<sys/select.h>
# include	"ISelect.hpp"

class	Select : public ISelect
{
public:
  Select(void);
  void	select(ITime const *timeout = nullptr);
  bool	can_read(ISocket const &socket);
  bool	can_write(ISocket const &socket);
  void	want_read(ISocket const &socket);
  void	want_write(ISocket const &socket);
private:
  fd_set	m_readfds;
  fd_set	m_writefds;
  int	m_nfds;
};

#endif		/* !SELECT_HPP_ */
