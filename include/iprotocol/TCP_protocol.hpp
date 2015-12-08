//
// TCP_protocol.hpp for TCP_protocol in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:35:29 2015 Antoine Plaskowski
// Last update Tue Dec  8 18:39:23 2015 Antoine Plaskowski
//

#ifndef		TCP_PROTOCOL_HPP_
# define	TCP_PROTOCOL_HPP_

# include	<cstdint>
# include	<string>
# include	<queue>
# include	"ITCP_protocol.hpp"

class	TCP_protocol : public ITCP_protocol
{
public:
  TCP_protocol(ITCP_protocol::callback const &callback);
  ~TCP_protocol(void);
  void	send(ITCP_client const &socket);
  void	recv(ITCP_client const &socket);
  void	result(ITCP_protocol::Error error);
  void	connect(std::string const &login, std::string const &password, uint8_t version);
  void	disconnect(void);
  void	ping(void);
  void	pong(void);
  void	list_games(void);
  //  void	games(std::list<Game *> const &games);
  void	create_game(void);
  void	join_game(std::string const &game);
  void	message(std::string const &login, std::string const &message);
  void	list_modes(void);
  //  void	modes(std::list<Mode *> const &modes);
  void	change_mode(std::string const &mode);
  void	list_params(void);
  //  void	params(std::list<Param *> const&params);
  void	change_param(std::string const &param, std::string const &value);
  void	list_meta_sprites(void);
  //  void	meta_sprites(std::list<Sprite *> const &sprites);
  //  void	take_sprite(Sprite const &sprite);
  //  void	give_sprite(Sprite const &sprite);
  void	list_meta_sounds(void);
  //  void	meta_sounds(std::list<Sound *> const &sounds);
  //  void	take_sound(Sound const &sound);
  //  void	give_sound(Sound const &sound);
  void	ready(bool ready);
  void	start(ITime const &time, uint16_t port);
  void	end(uint64_t score, bool winner);
  void	leave(void);
  void	set_callback(ITCP_protocol::callback const &callback);
private:
  ITCP_protocol::callback	m_callback;
  TCP_packet_recv	m_recv;
  std::queue<TCP_packet_send *>	m_send;
};

#endif		/* !TCP_PROTOCOL_HPP_ */
