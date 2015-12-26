//
// BasicGame.hpp for BasicGame in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 10:12:30 2015 Alaric Degand
// Last update Sat Dec 26 14:09:49 2015 Antoine Plaskowski
//

#ifndef		BASICGAME_HPP_
# define	BASICGAME_HPP_

# include	<list>
# include	<map>
# include	"IGame.hpp"
# include	"ISelect.hpp"
# include	"Usine.hpp"
# include	"Player.hpp"
# include	"IEntite.hpp"
# include	"PortGenerator.hpp"
# include	"UDP_server.hpp"
# include	"IUDP_protocol.hpp"

class		BasicGame: public IGame, public IUDP_protocol::Callback
{
public:
  BasicGame(std::string const &owner, Usine<fct_new_ientite> &usine, std::string const &name, PortGenerator &port_generator);
  ~BasicGame(void);
  void	run(void);
  std::string const	&get_owner(void) const;
  void	set_name(std::string const &name);
  std::string const	&get_name(void) const;
  void	add_player(std::string const &login);
  void	sup_player(std::string const &login);
  std::list<std::string> const	&get_player(void) const;
  std::map<std::string, std::string> const	&get_meta_params(void) const;
  void	set_param(std::string const &name, std::string const &value);
  void	sprites(IUDP_protocol &, std::string const &, std::list<IUDP_protocol::Sprite *> const &);
  void	sounds(IUDP_protocol &, std::string const &, std::list<IUDP_protocol::Sound *> const &);
  void	input(IUDP_protocol &, std::string const &, IUDP_protocol::Input const &);
  void	sprites(IUDP_protocol &, std::string const &, std::list<IUDP_protocol::Sprite *> const &, IUDP_server::u_sockaddr const &, socklen_t);
  void	sounds(IUDP_protocol &, std::string const &, std::list<IUDP_protocol::Sound *> const &, IUDP_server::u_sockaddr const &, socklen_t);
  void	input(IUDP_protocol &iudp_protocol, std::string const &login, IUDP_protocol::Input const &input, IUDP_server::u_sockaddr const &sockaddr, socklen_t len);
private:
  std::string const	m_owner;
  std::string	m_name;
  uintmax_t const	m_player_max;
  uintmax_t const	m_x;
  uintmax_t const	m_y;
  std::list<std::string>	m_login;
  std::map<std::string, std::string>	m_params;
  std::list<Player *>	m_players;
  std::list<IEntite *>	m_ientites;
  Usine<fct_new_ientite>	&m_usine;
  Port	m_port;
  ISelect	&m_iselect;
  IUDP_server	&m_iudp_server;
};

#endif		/* !BASICGAME_HPP_ */
