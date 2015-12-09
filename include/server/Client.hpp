//
// Client.hpp for Client in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:53:39 2015 Alaric Degand
// Last update Wed Dec  9 23:30:06 2015 Antoine Plaskowski
//

#ifndef		CLIENT_HPP_
# define	CLIENT_HPP_

class		Client;

#include	"Server.hpp"
#include	"ITCP_client.hpp"
#include	"TCP_protocol.hpp"

class		Client : public ITCP_protocol::Callback
{
public:
  Client(Server &server, ITCP_client &itcp_client);
  ~Client(void);
  void	result(ITCP_protocol &itcp_protocol, bool ready);
  void	connect(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &password);
  void	disconnect(ITCP_protocol &itcp_protocol);
  void	ping(ITCP_protocol &itcp_protocol);
  void	pong(ITCP_protocol &itcp_protocol);
  void	list_meta_games(ITCP_protocol &itcp_protocol);
  void	meta_games(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Game *> const &games);
  void	create_game(ITCP_protocol &itcp_protocol, ITCP_protocol::Game const &game);
  void	join_game(ITCP_protocol &itcp_protocol, ITCP_protocol::Game const &game);
  void	message(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &message);
  //  void	list_modes(ITCP_protocol &itcp_protocol);
  //  void	meta_modes(ITCP_protocol &itcp_protocol, std::list<Mode *> const &modes);
  //  void	change_mode(ITCP_protocol &itcp_protocol, std::string const &mode);
  void	list_meta_params(ITCP_protocol &itcp_protocol);
  void	meta_params(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Param *> const&params);
  void	change_param(ITCP_protocol &itcp_protocol, ITCP_protocol::Param const &param);
  void	list_meta_sprites(ITCP_protocol &itcp_protocol);
  void	meta_sprites(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Sprite *> const &sprites);
  void	take_sprite(ITCP_protocol &itcp_protocol, ITCP_protocol::Sprite const &sprite);
  void	give_sprite(ITCP_protocol &itcp_protocol, ITCP_protocol::Sprite const &sprite);
  void	list_meta_sounds(ITCP_protocol &itcp_protocol);
  void	meta_sounds(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Sound *> const &sounds);
  void	take_sound(ITCP_protocol &itcp_protocol, ITCP_protocol::Sound const &sound);
  void	give_sound(ITCP_protocol &itcp_protocol, ITCP_protocol::Sound const &sound);
  void	ready(ITCP_protocol &itcp_protocol, bool ready);
  void	start(ITCP_protocol &itcp_protocol, uint8_t second, uint16_t port);
  void	end(ITCP_protocol &itcp_protocol, uint64_t score, bool winner);
  void	leave(ITCP_protocol &itcp_protocol);
private:
  Server	&m_server;
  ITCP_client	&m_itcp_client;
  ITCP_protocol	&m_itcp_protocol;
  std::string	m_login;
  std::string	m_password;
};

#endif		/* !CLIENT_HPP_ */
