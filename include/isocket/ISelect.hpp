//
// ISelect.hpp for ISelect in /home/plasko_a/projet/cplusplus/rtype/include/isocket
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Dec  8 13:56:31 2015 Antoine Plaskowski
// Last update Tue Dec  8 15:42:47 2015 Antoine Plaskowski
//

#ifndef		ISELECT_HPP_
# define	ISELECT_HPP_

# include	"ISocket.hpp"
# include	"ITime.hpp"

class	ISelect
{
public:
  virtual ~ISelect(void);
  virtual void	select(ITime const *timeout = nullptr) = 0;
  virtual bool	can_read(ISocket const &socket) = 0;
  virtual bool	can_write(ISocket const &socket) = 0;
  virtual void	want_read(ISocket const &socket) = 0;
  virtual void	want_write(ISocket const &socket) = 0;
};

class	ISelect_exception : public std::exception
{
public:
  virtual ~ISelect_exception(void);
};

#endif		/* !ISELECT_HPP_ */
