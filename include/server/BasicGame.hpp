//
// BasicGame.hpp for BasicGame in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 10:12:30 2015 Alaric Degand
// Last update Fri Dec 25 11:37:10 2015 Antoine Plaskowski
//

#ifndef		BASICGAME_HPP_
# define	BASICGAME_HPP_

# include	<list>
# include	<map>
# include	"IGame.hpp"
# include	"Usine.hpp"
# include	"PortGenerator.hpp"
# include	"UDP_server.hpp"

class		BasicGame: public IGame
{
public:
  BasicGame(std::string const &owner, Usine<fct_new_ientite> &usine, std::string const &name, PortGenerator &port_generator);
  ~BasicGame(void);
  void	run(void);
  std::string const	&get_owner(void) const;
  void	set_name(std::string const &name);
  std::string const	&get_name(void) const;
  std::map<std::string, std::string> const	&get_meta_params(void) const;
  void	set_param(std::string const &name, std::string const &value);
private:
  std::string const	m_owner;
  std::string	m_name;
  std::list<std::string>	m_player;
  std::map<std::string, std::string>	m_params;
  Usine<fct_new_ientite>	&m_usine;
  Port	m_port;
  IUDP_server	&m_iudp_server;
};

#endif		/* !BASICGAME_HPP_ */
