//
// TCP_protocol.cpp for TCP_protocol in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:40:34 2015 Antoine Plaskowski
// Last update Wed Dec  9 01:01:24 2015 Antoine Plaskowski
//

#include	"TCP_protocol.hpp"

TCP_protocol::TCP_protocol(ITCP_protocol::callback const &callback) :
  m_callback(callback)
{
}

TCP_protocol::~TCP_protocol(void)
{
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
      break;
    case ATCP_packet::Connect:
      break;
    case ATCP_packet::Disconnect:
      break;
    case ATCP_packet::Ping:
      break;
    case ATCP_packet::Pong:
      break;
    case ATCP_packet::List_games:
      break;
    case ATCP_packet::Games:
      break;
    case ATCP_packet::Create_game:
      break;
    case ATCP_packet::Join_game:
      break;
    case ATCP_packet::Message:
      break;
    case ATCP_packet::List_modes:
      break;
    case ATCP_packet::Modes:
      break;
    case ATCP_packet::Change_mode:
      break;
    case ATCP_packet::List_params:
      break;
    case ATCP_packet::Params:
      break;
    case ATCP_packet::Change_param:
      break;
    case ATCP_packet::List_meta_sprites:
      break;
    case ATCP_packet::Meta_sprites:
      break;
    case ATCP_packet::Take_sprite:
      break;
    case ATCP_packet::Give_sprite:
      break;
    case ATCP_packet::List_meta_sounds:
      break;
    case ATCP_packet::Meta_sounds:
      break;
    case ATCP_packet::Take_sound:
      break;
    case ATCP_packet::Give_sound:
      break;
    case ATCP_packet::Ready:
      break;
    case ATCP_packet::Start:
      break;
    case ATCP_packet::End:
      break;
    case ATCP_packet::Leave:
      break;
    default:
      throw std::exception();
    }
  m_to_recv.reset();
}

void	TCP_protocol::send_result(ITCP_protocol::Error error)
{
  TCP_packet_send	&to_send = get_to_send();
  to_send.put(error);
  set_to_send(to_send, ATCP_packet::Result);
}

void	TCP_protocol::send_connect(std::string const &login, std::string const &password, uint8_t version)
{
  TCP_packet_send	&to_send = get_to_send();
  to_send.put(login);
  to_send.put(password);
  to_send.put(version);
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

void	TCP_protocol::send_list_games(void)
{
 TCP_packet_send	&to_send = get_to_send();
 set_to_send(to_send, ATCP_packet::List_games);
}
//void	TCP_protocol::send_games(std::list<Game *> const &games)
void	TCP_protocol::send_create_game(void)
{
 TCP_packet_send	&to_send = get_to_send();
 set_to_send(to_send, ATCP_packet::Create_game);
}

void	TCP_protocol::send_join_game(std::string const &game)
{
   TCP_packet_send	&to_send = get_to_send();
   to_send.put(game);
   set_to_send(to_send, ATCP_packet::Join_game);
}

void	TCP_protocol::send_message(std::string const &login, std::string const &message)
{
 TCP_packet_send	&to_send = get_to_send();
 to_send.put(login);
 to_send.put(message);
 set_to_send(to_send, ATCP_packet::Join_game);
}

void	TCP_protocol::send_list_modes(void)
{
  TCP_packet_send	&to_send = get_to_send();
  set_to_send(to_send, ATCP_packet::List_modes);
}

//void	TCP_protocol::send_modes(std::list<Mode *> const &modes)
void	TCP_protocol::send_change_mode(std::string const &mode)
{
  TCP_packet_send	&to_send = get_to_send();
  to_send.put(mode);
  set_to_send(to_send, ATCP_packet::Change_mode);
}

void	TCP_protocol::send_list_params(void)
{
  TCP_packet_send	&to_send = get_to_send();
  set_to_send(to_send, ATCP_packet::List_params);
}

//void	TCP_protocol::send_params(std::list<Param *> const&params)
void	TCP_protocol::send_change_param(std::string const &param, std::string const &value)
{
 TCP_packet_send	&to_send = get_to_send();
 to_send.put(param);
 to_send.put(value);
 set_to_send(to_send, ATCP_packet::Change_param);
}

void	TCP_protocol::send_list_meta_sprites(void)
{
  TCP_packet_send	&to_send = get_to_send();
  set_to_send(to_send, ATCP_packet::List_meta_sounds);
}

//void	TCP_protocol::send_meta_sprites(std::list<Sprite *> const &sprites)
//void	TCP_protocol::send_take_sprite(Sprite const &sprite)
//void	TCP_protocol::send_give_sprite(Sprite const &sprite)
void	TCP_protocol::send_list_meta_sounds(void)
{
  TCP_packet_send	&to_send = get_to_send();
  set_to_send(to_send, ATCP_packet::Create_game);
}

//void	TCP_protocol::send_meta_sounds(std::list<Sound *> const &sounds)
//void	TCP_protocol::send_take_sound(Sound const &sound)
//void	TCP_protocol::send_give_sound(Sound const &sound)
void	TCP_protocol::send_ready(bool ready)
{
  TCP_packet_send	&to_send = get_to_send();
  to_send.put(ready);
  set_to_send(to_send, ATCP_packet::Create_game);
}

void	TCP_protocol::send_start(ITime const &time, uint16_t port)
{
  TCP_packet_send	&to_send = get_to_send();
  to_send.put(time.get_second());
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

//void	TCP_protocol::set_callback(ITCP_protocol::callback &callback)

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
