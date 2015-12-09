//
// Client.hpp for Client in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:53:39 2015 Alaric Degand
// Last update Wed Dec  9 16:20:27 2015 Antoine Plaskowski
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
  void	list_games(ITCP_protocol &itcp_protocol);
  //  void	games(ITCP_protocol &itcp_protocol, std::list<Game *> const &games);
  void	create_game(ITCP_protocol &itcp_protocol);
  void	join_game(ITCP_protocol &itcp_protocol, std::string const &game);
  void	message(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &message);
  void	list_modes(ITCP_protocol &itcp_protocol);
  //  void	modes(ITCP_protocol &itcp_protocol, std::list<Mode *> const &modes);
  void	change_mode(ITCP_protocol &itcp_protocol, std::string const &mode);
  void	list_params(ITCP_protocol &itcp_protocol);
  //  void	params(ITCP_protocol &itcp_protocol, std::list<Param *> const&params);
  void	change_param(ITCP_protocol &itcp_protocol, std::string const &param, std::string const &value);
  void	list_meta_sprites(ITCP_protocol &itcp_protocol);
  //  void	meta_sprites(ITCP_protocol &itcp_protocol, std::list<Sprite *> const &sprites);
  //  void	take_sprite(ITCP_protocol &itcp_protocol, Sprite const &sprite);
  //  void	give_sprite(ITCP_protocol &itcp_protocol, Sprite const &sprite);
  void	list_meta_sounds(ITCP_protocol &itcp_protocol);
  //  void	meta_sounds(ITCP_protocol &itcp_protocol, std::list<Sound *> const &sounds);
  //  void	take_sound(ITCP_protocol &itcp_protocol, Sound const &sound);
  //  void	give_sound(ITCP_protocol &itcp_protocol, Sound const &sound);
  void	ready(ITCP_protocol &itcp_protocol, bool ready);
  void	start(ITCP_protocol &itcp_protocol, uint8_t second, uint16_t port);
  void	end(ITCP_protocol &itcp_protocol, uint64_t score, bool winner);
  void	leave(ITCP_protocol &itcp_protocol);
private:
  Server	&m_server;
  ITCP_client	&m_itcp_client;
  ITCP_protocol	&m_itcp_protocol;
  std::string	login;
  std::string	password;
};

#endif		/* !CLIENT_HPP_ */
