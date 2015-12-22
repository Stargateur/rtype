//
// UDP_protocol.hpp for UDP_protocol in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:35:29 2015 Antoine Plaskowski
// Last update Tue Dec 22 16:50:50 2015 Antoine Plaskowski
//

#ifndef		UDP_PROTOCOL_HPP_
# define	UDP_PROTOCOL_HPP_

# include	<cstdint>
# include	<string>
# include	<array>
# include	"IUDP_protocol.hpp"
# include	"ISelect.hpp"

class	UDP_protocol : public IUDP_protocol
{
public:
  UDP_protocol(IUDP_protocol::Callback &callback);
  ~UDP_protocol(void);
private:
  UDP_packet_send	&get_to_send(void);
  void	set_to_send(UDP_packet_send &to_send, AUDP_packet::Opcode opcode);
  //  void	set_callback(IUDP_protocol::Callback &callback);
public:
  bool	want_send(void) const;
  bool	want_recv(void) const;
  void	send(IUDP_client const &socket);
  void	recv(IUDP_client const &socket);
  void	send_result(IUDP_protocol::Error error);
  void	send_connect(std::string const &login, std::string const &password);
  void	send_disconnect(void);
  void	send_ping(void);
  void	send_pong(void);
  void	send_list_meta_games(void);
  void	send_meta_games(std::list<IUDP_protocol::Game *> const &games);
  void	send_create_game(IUDP_protocol::Game const &game);
  void	send_join_game(IUDP_protocol::Game const &game);
  void	send_message(std::string const &login, std::string const &message);
  //  void	send_list_modes(void);
  //  void	send_meta_modes(std::list<Mode *> const &modes);
  //  void	send_change_mode(std::string const &mode);
  void	send_list_meta_params(void);
  void	send_meta_params(std::list<IUDP_protocol::Param *> const &params);
  void	send_change_param(IUDP_protocol::Param const &param);
  void	send_list_meta_sprites(void);
  void	send_meta_sprites(std::list<IUDP_protocol::Sprite *> const &sprites);
  void	send_take_sprite(Sprite const &sprite);
  void	send_give_sprite(Sprite const &sprite);
  void	send_list_meta_sounds(void);
  void	send_meta_sounds(std::list<IUDP_protocol::Sound *> const &sounds);
  void	send_take_sound(IUDP_protocol::Sound const &sound);
  void	send_give_sound(IUDP_protocol::Sound const &sound);
  void	send_ready(bool ready);
  void	send_start(uint8_t second, uint16_t port);
  void	send_end(uint64_t score, bool winner);
  void	send_leave(void);
  template<typename... Ts>
  void	test(AUDP_packet::Opcode opcode, Ts... args)
  {
    if (sizeof...(args) > 0)
      test(opcode, args...);
    else
      {
	UDP_packet_send	&to_send = get_to_send();
	set_to_send(to_send, opcode);
      }
  }
  template<typename T, typename... Ts>
  void	test(AUDP_packet::Opcode opcode, T first, Ts... args)
  {
    UDP_packet_send	&to_send = get_to_send();
    to_send.put(first);
    test(opcode, first, args...);
  }
private:
  void	recv_result(void);
  void	recv_connect(void);
  void	recv_disconnect(void);
  void	recv_ping(void);
  void	recv_pong(void);
  void	recv_list_meta_games(void);
  void	recv_meta_games(void);
  void	recv_create_game(void);
  void	recv_join_game(void);
  void	recv_message(void);
  //  void	recv_list_modes(void);
  //  void	recv_meta_modes(void);
  //  void	recv_change_mode(void);
  void	recv_list_meta_params(void);
  void	recv_meta_params(void);
  void	recv_change_param(void);
  void	recv_list_meta_sprites(void);
  void	recv_meta_sprites(void);
  void	recv_take_sprite(void);
  void	recv_give_sprite(void);
  void	recv_list_meta_sounds(void);
  void	recv_meta_sounds(void);
  void	recv_take_sound(void);
  void	recv_give_sound(void);
  void	recv_ready(void);
  void	recv_start(void);
  void	recv_end(void);
  void	recv_leave(void);
private:
  IUDP_protocol::Callback	&m_callback;
  UDP_packet_recv	m_to_recv;
  std::array<UDP_packet_send, UINT8_MAX + 1>	m_to_send;
  uint8_t	m_idx_to_send;
  uint8_t	m_idx_to_stock;
};

#endif		/* !UDP_PROTOCOL_HPP_ */
