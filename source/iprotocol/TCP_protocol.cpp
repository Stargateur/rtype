//
// TCP_protocol.cpp for TCP_protocol in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:40:34 2015 Antoine Plaskowski
// Last update Wed Dec  9 23:35:33 2015 Antoine Plaskowski
//

#include	<algorithm>
#include	"TCP_protocol.hpp"

TCP_protocol::TCP_protocol(ITCP_protocol::Callback &callback) :
  m_callback(callback)
{
}

TCP_protocol::~TCP_protocol(void)
{
}

void	TCP_protocol::set_callback(ITCP_protocol::Callback &callback)
{
  m_callback = callback;
}

TCP_packet_send	&TCP_protocol::get_to_send(void)
{
  return (m_to_send[m_idx_to_stock]);
}

void	TCP_protocol::set_to_send(TCP_packet_send &to_send, ATCP_packet::Opcode opcode)
{
  to_send.set_opcode(opcode);
  if (m_idx_to_stock++ == m_idx_to_send)
    m_idx_to_send++;
}

bool	TCP_protocol::want_send(void) const
{
  return (m_idx_to_send != m_idx_to_stock);
}

bool	TCP_protocol::want_recv(void) const
{
  return (true);
}

void	TCP_protocol::send(ITCP_client const &socket)
{
  TCP_packet_send	&to_send = m_to_send[m_idx_to_send];

  if (to_send.send(socket) == true)
    m_idx_to_send++;
}

void	TCP_protocol::recv(ITCP_client const &socket)
{
  if (m_to_recv.recv(socket) == false)
    return;
  switch (m_to_recv.get_opcode())
    {
    case ATCP_packet::Result:
      recv_result();
      return;
    case ATCP_packet::Connect:
      recv_connect();
      return;
    case ATCP_packet::Disconnect:
      recv_disconnect();
      return;
    case ATCP_packet::Ping:
      recv_ping();
      return;
    case ATCP_packet::Pong:
      recv_pong();
      return;
    case ATCP_packet::List_meta_games:
      recv_list_meta_games();
      return;
    case ATCP_packet::Games:
      recv_meta_games();
      return;
    case ATCP_packet::Create_game:
      recv_create_game();
      return;
    case ATCP_packet::Join_game:
      recv_join_game();
      return;
    case ATCP_packet::Message:
      recv_message();
      return;
    case ATCP_packet::List_meta_modes:
      //recv_list_modes();
      return;
    case ATCP_packet::Modes:
      //recv_meta_modes();
      return;
    case ATCP_packet::Change_mode:
      //recv_change_mode();
      return;
    case ATCP_packet::List_meta_params:
      recv_list_meta_params();
      return;
    case ATCP_packet::Params:
      recv_meta_params();
      return;
    case ATCP_packet::Change_param:
      recv_change_param();
      return;
    case ATCP_packet::List_meta_sprites:
      recv_list_meta_sprites();
      return;
    case ATCP_packet::Meta_sprites:
      recv_meta_sprites();
      return;
    case ATCP_packet::Take_sprite:
      recv_take_sprite();
      return;
    case ATCP_packet::Give_sprite:
      recv_give_sprite();
      return;
    case ATCP_packet::List_meta_sounds:
      recv_list_meta_sounds();
      return;
    case ATCP_packet::Meta_sounds:
      recv_meta_sounds();
      return;
    case ATCP_packet::Take_sound:
      recv_take_sound();
      return;
    case ATCP_packet::Give_sound:
      recv_give_sound();
      return;
    case ATCP_packet::Ready:
      recv_ready();
      return;
    case ATCP_packet::Start:
      recv_start();
      return;
    case ATCP_packet::End:
      recv_end();
      return;
    case ATCP_packet::Leave:
      recv_leave();
      return;
    }
  throw std::exception();
}

void	TCP_protocol::send_result(ITCP_protocol::Error error)
{
  TCP_packet_send	&to_send = get_to_send();
  to_send.put(error);
  set_to_send(to_send, ATCP_packet::Result);
}

void	TCP_protocol::send_connect(std::string const &login, std::string const &password)
{
  TCP_packet_send	&to_send = get_to_send();
  to_send.put(login);
  to_send.put(password);
  to_send.put<uint8_t>(1);
  set_to_send(to_send, ATCP_packet::Connect);
}

void	TCP_protocol::send_disconnect(void)
{
  TCP_packet_send	&to_send = get_to_send();
  set_to_send(to_send, ATCP_packet::Disconnect);
}

void	TCP_protocol::send_ping(void)
{
  TCP_packet_send	&to_send = get_to_send();
  set_to_send(to_send, ATCP_packet::Ping);
}

void	TCP_protocol::send_pong(void)
{
  TCP_packet_send	&to_send = get_to_send();
  set_to_send(to_send, ATCP_packet::Pong);
}

void	TCP_protocol::send_list_meta_games(void)
{
 TCP_packet_send	&to_send = get_to_send();
 set_to_send(to_send, ATCP_packet::List_meta_games);
}

void	TCP_protocol::send_meta_games(std::list<ITCP_protocol::Game *> const &games)
{
  TCP_packet_send	&to_send = get_to_send();

  to_send.put<uint8_t>(games.size());
  for (auto n : games)
    {
      //      to_send.put(
    }
}

void	TCP_protocol::send_create_game(ITCP_protocol::Game const &game)
{
 TCP_packet_send	&to_send = get_to_send();
 
 set_to_send(to_send, ATCP_packet::Create_game);
}

void	TCP_protocol::send_join_game(ITCP_protocol::Game const &game)
{
   TCP_packet_send	&to_send = get_to_send();
   //   to_send.put(game);
   set_to_send(to_send, ATCP_packet::Join_game);
}

void	TCP_protocol::send_message(std::string const &login, std::string const &message)
{
 TCP_packet_send	&to_send = get_to_send();
 to_send.put(login);
 to_send.put(message);
 set_to_send(to_send, ATCP_packet::Join_game);
}

// void	TCP_protocol::send_list_meta_modes(void)
// {
//   TCP_packet_send	&to_send = get_to_send();
//   set_to_send(to_send, ATCP_packet::List_modes);
// }

// void	TCP_protocol::send_meta_modes(std::list<Mode *> const &modes)

// void	TCP_protocol::send_change_mode(std::string const &mode)
// {
//   TCP_packet_send	&to_send = get_to_send();
//   to_send.put(mode);
//   set_to_send(to_send, ATCP_packet::Change_mode);
// }

void	TCP_protocol::send_list_meta_params(void)
{
  TCP_packet_send	&to_send = get_to_send();
  set_to_send(to_send, ATCP_packet::List_meta_params);
}

void	TCP_protocol::send_meta_params(std::list<ITCP_protocol::Param *> const &params)
{
  
}

void	TCP_protocol::send_change_param(ITCP_protocol::Param const &param)
{
 TCP_packet_send	&to_send = get_to_send();

 set_to_send(to_send, ATCP_packet::Change_param);
}

void	TCP_protocol::send_list_meta_sprites(void)
{
  TCP_packet_send	&to_send = get_to_send();
  set_to_send(to_send, ATCP_packet::List_meta_sounds);
}

void	TCP_protocol::send_meta_sprites(std::list<ITCP_protocol::Sprite *> const &sprites)
{
}

void	TCP_protocol::send_take_sprite(ITCP_protocol::Sprite const &sprite)
{
}

void	TCP_protocol::send_give_sprite(ITCP_protocol::Sprite const &sprite)
{
}

void	TCP_protocol::send_list_meta_sounds(void)
{
  TCP_packet_send	&to_send = get_to_send();
  set_to_send(to_send, ATCP_packet::Create_game);
}

void	TCP_protocol::send_meta_sounds(std::list<ITCP_protocol::Sound *> const &sounds)
{
}

void	TCP_protocol::send_take_sound(ITCP_protocol::Sound const &sound)
{
}

void	TCP_protocol::send_give_sound(ITCP_protocol::Sound const &sound)
{
}

void	TCP_protocol::send_ready(bool ready)
{
  TCP_packet_send	&to_send = get_to_send();
  to_send.put(ready);
  set_to_send(to_send, ATCP_packet::Create_game);
}

void	TCP_protocol::send_start(uint8_t second, uint16_t port)
{
  TCP_packet_send	&to_send = get_to_send();
  to_send.put(second);
  to_send.put(port);
  set_to_send(to_send, ATCP_packet::Create_game);
}

void	TCP_protocol::send_end(uint64_t score, bool winner)
{
  // TCP_packet_send	&to_send = get_to_send();
  // to_send.put(score);
  // to_send.put(winner);
  // set_to_send(to_send, ATCP_packet::End);
  test(ATCP_packet::End, score, winner);
}

void	TCP_protocol::send_leave(void)
{
  test(ATCP_packet::Leave);
}

void	TCP_protocol::recv_result(void)
{
  ITCP_protocol::Error	error;
  m_to_recv.get(error);
  m_to_recv.reset();
  m_callback.result(*this, error);
}

void	TCP_protocol::recv_connect(void)
{
  std::string	login;
  std::string	password;
  uint8_t	version;

  m_to_recv.get(login);
  m_to_recv.get(password);
  m_to_recv.get(version);
  m_to_recv.reset();
  if (version != 1) // chiant !
    throw std::exception();
  m_callback.connect(*this, login, password);
}

void	TCP_protocol::recv_disconnect(void)
{
  m_to_recv.reset();
  m_callback.disconnect(*this);
}

void	TCP_protocol::recv_ping(void)
{
  m_to_recv.reset();
  m_callback.ping(*this);
}

void	TCP_protocol::recv_pong(void)
{
  m_to_recv.reset();
  m_callback.pong(*this);
}

void	TCP_protocol::recv_list_meta_games(void)
{
  m_to_recv.reset();
  m_callback.list_meta_games(*this);
}

void	TCP_protocol::recv_meta_games(void)
{
}

void	TCP_protocol::recv_create_game(void)
{
  m_to_recv.reset();
  //  m_callback.create_game(*this);
}

void	TCP_protocol::recv_join_game(void)
{
  m_to_recv.reset();
  //  m_callback.join_game(*this, game);
}

void	TCP_protocol::recv_message(void)
{
  std::string	login;
  std::string	message;
  m_to_recv.get(login);
  m_to_recv.get(message);
  m_to_recv.reset();
  m_callback.message(*this, login, message);
}

// void	TCP_protocol::recv_list_modes(void)
// {
//   m_to_recv.reset();
//   m_callback.list_modes(*this);
// }

// void	TCP_protocol::recv_meta_modes(void)

// void	TCP_protocol::recv_change_mode(void)
// {
//   std::string	mode;
//   m_to_recv.get(mode);
//   m_to_recv.reset();
//   m_callback.change_mode(*this, mode);
// }

void	TCP_protocol::recv_list_meta_params(void)
{
  m_to_recv.reset();
  m_callback.list_meta_params(*this);
}

void	TCP_protocol::recv_meta_params(void)
{
}

void	TCP_protocol::recv_change_param(void)
{
  m_to_recv.reset();
  //  m_callback.change_param(*this, param, value);
}

void	TCP_protocol::recv_list_meta_sprites(void)
{
  m_to_recv.reset();
  m_callback.list_meta_sprites(*this);
}

void	TCP_protocol::recv_meta_sprites(void)
{
}

void	TCP_protocol::recv_take_sprite(void)
{
}

void	TCP_protocol::recv_give_sprite(void)
{
}
void	TCP_protocol::recv_list_meta_sounds(void)
{
  m_to_recv.reset();
  m_callback.list_meta_sounds(*this);
}

void	TCP_protocol::recv_meta_sounds(void)
{
}

void	TCP_protocol::recv_take_sound(void)
{
}

void	TCP_protocol::recv_give_sound(void)
{
}

void	TCP_protocol::recv_ready(void)
{
  bool	ready;
  m_to_recv.get(ready);
  m_to_recv.reset();
  m_callback.ready(*this, ready);
}

void	TCP_protocol::recv_start(void)
{
  uint8_t	second;
  uint16_t	port;
  m_to_recv.get(second);
  m_to_recv.get(port);
  m_to_recv.reset();
  m_callback.start(*this, second, port);
}

void	TCP_protocol::recv_end(void)
{
  uint64_t	score;
  bool	winner;
  m_to_recv.get(score);
  m_to_recv.get(winner);
  m_to_recv.reset();
  m_callback.end(*this, score, winner);
}

void	TCP_protocol::recv_leave(void)
{
  m_to_recv.reset();
  m_callback.leave(*this);
}
