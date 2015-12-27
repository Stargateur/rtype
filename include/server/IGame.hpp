//
// IGame.hpp for IGame in /home/plasko_a/projet/cplusplus/rtype/include/server
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Dec 10 17:33:48 2015 Antoine Plaskowski
// Last update Sun Dec 27 10:32:53 2015 Antoine Plaskowski
//

#ifndef		IGAME_HPP_
# define	IGAME_HPP_

# include	<list>
# include	<map>
# include	<vector>
# include	"Player.hpp"
# include	"Background.hpp"

class	IGame
{
 public:
  IGame(/*IGame const &*/);
  virtual ~IGame(void);
  IGame	&operator=(IGame const &igame);
  virtual void	run(void) = 0;
  virtual std::string const	&get_owner(void) const = 0;
  virtual void	set_name(std::string const &name) = 0;
  virtual std::string const	&get_name(void) const = 0;
  virtual void	add_login(std::string const &login) = 0;
  virtual void	sup_login(std::string const &login) = 0;
  virtual std::list<std::string> const	&get_logins(void) const = 0;
  virtual std::map<std::string, std::string> const	&get_meta_params(void) const = 0;
  virtual std::vector<Player *> const	&get_players(void) const = 0;
  virtual std::vector<IEntite *> const	&get_ientites(void) const = 0;
  virtual Background const	&get_background(void) const = 0;
};

#endif		/* !IGAME_HPP_ */
