//
// Client.cpp for Client in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:56:02 2015 Alaric Degand
// Last update Sun Dec 27 18:09:04 2015 Antoine Plaskowski
//

#include	"Client.hpp"

Client::Client(Server &server, ITCP_client &itcp_client) :
  m_server(server),
  m_itcp_client(itcp_client),
  m_itcp_protocol(*new TCP_protocol(*this)),
  m_last(nullptr),
  m_wait_pong(false),
  m_ready(false)
{
}

Client::~Client(void)
{
  delete &m_itcp_client;
  delete &m_itcp_protocol;
  delete m_last;
}

void	Client::pre_run(ISelect &iselect)
{
  if (m_itcp_protocol.want_recv() == true)
    iselect.want_read(m_itcp_client);
  if (m_itcp_protocol.want_send() == true)
    iselect.want_write(m_itcp_client);
}

void	Client::run(ISelect const &iselect, ITime const &timeout)
{
  if (m_last == nullptr)
    m_last = &timeout.clone();
  if (iselect.can_read(m_itcp_client) == true)
    {
      m_last->now();
      m_itcp_protocol.recv(m_itcp_client);
    }
  this->timeout(timeout);
  if (iselect.can_write(m_itcp_client) == true)
    m_itcp_protocol.send(m_itcp_client);
}

void	Client::timeout(ITime const &timeout)
{
  intmax_t      second = m_last->get_second();
  intmax_t      nano = m_last->get_nano();

  m_last->now();
  if (m_last->get_second() - second > timeout.get_second() ||
      (m_last->get_second() - second == timeout.get_second() && m_last->get_nano() - nano > timeout.get_nano()))
    {
      if (m_wait_pong == true)
	throw std::logic_error("timeout");
      m_wait_pong = true;
      m_itcp_protocol.send_ping();
      return;
    }
  m_last->set_second(second);
  m_last->set_nano(nano);
}

void	Client::result(ITCP_protocol &, ITCP_protocol::Error)
{
}

void	Client::connect(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &password)
{
  if (m_server.check_login(login, password))
    {
      m_login = login;
      m_password = password;
    }
  else
    itcp_protocol.send_result(ITCP_protocol::WRONGLOGIN);
}

void	Client::disconnect(ITCP_protocol &)
{
  m_login.clear();
  m_password.clear();
  throw std::logic_error("disconnect");
}

void	Client::ping(ITCP_protocol &itcp_protocol)
{
  itcp_protocol.send_pong();
}

void	Client::pong(ITCP_protocol &)
{
  m_wait_pong = false;
}

void	Client::list_meta_games(ITCP_protocol &itcp_protocol)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
  else
    {
      std::list<ITCP_protocol::Game *>	games;
      
      for (auto game : m_server.get_games())
	games.push_back(new ITCP_protocol::Game({game->get_name(), game->get_owner(), 0, 0}));
      m_itcp_protocol.send_meta_games(games);
      for (auto game : games)
	delete game;
    }
}

void	Client::meta_games(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Game *> const &)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::create_game(ITCP_protocol &itcp_protocol, ITCP_protocol::Game const &)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
  else
    m_server.create_game(get_login());
}

void	Client::join_game(ITCP_protocol &itcp_protocol, ITCP_protocol::Game const &game)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
  else
    m_server.join_game(get_login(), game.owner);
}

void	Client::message(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &message)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::list_meta_params(ITCP_protocol &itcp_protocol)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::meta_params(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Param *> const &)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::change_param(ITCP_protocol &itcp_protocol, ITCP_protocol::Param const &param)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::list_meta_sprites(ITCP_protocol &itcp_protocol)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
  else
    {
      IGame const &game = m_server.get_game(get_login());
      std::list<ITCP_protocol::Sprite *>	sprites;
      for (auto player : game.get_players())
	{
	  File const &file = player->get_sprite();
	  sprites.push_back(new ITCP_protocol::Sprite({file.get_name(), file.get_checksome(), player->get_id(), nullptr, static_cast<uint16_t>(file.get_size())}));
	}
      for (auto ientite : game.get_ientites())
	{
	  File const &file = ientite->get_sprite();
	  sprites.push_back(new ITCP_protocol::Sprite({file.get_name(), file.get_checksome(), ientite->get_id(), nullptr, static_cast<uint16_t>(file.get_size())}));
	}
      Background const   &background = game.get_background();
      File const &file = background.get_sprite();
      sprites.push_back(new ITCP_protocol::Sprite({file.get_name(), file.get_checksome(), background.get_id(), nullptr, static_cast<uint16_t>(file.get_size())}));
      m_itcp_protocol.send_meta_sprites(sprites);
      for (auto sprite : sprites)
	delete sprite;
    }
}

void	Client::meta_sprites(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Sprite *> const &)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::take_sprite(ITCP_protocol &itcp_protocol, ITCP_protocol::Sprite const &sprite)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
  else
    {
      IGame const &game = m_server.get_game(get_login());
      for (auto player : game.get_players())
	{
	  if (player->get_id() == sprite.id)
	    {
	      File const &file = player->get_sprite();
	      ITCP_protocol::Sprite	sprite = {file.get_name(), file.get_checksome(), player->get_id(), file.get_data(), file.get_size()};
	      m_itcp_protocol.send_give_sprite(sprite);
	      return;
	    }
	}
      for (auto ientite : game.get_ientites())
	{
	  if (ientite->get_id() == sprite.id)
	    {
	      File const &file = ientite->get_sprite();
	      ITCP_protocol::Sprite	sprite = {file.get_name(), file.get_checksome(), ientite->get_id(), file.get_data(), file.get_size()};
	      m_itcp_protocol.send_give_sprite(sprite);
	      return;
	    }
	}
      Background const   &background = game.get_background();
      if (background.get_id() == sprite.id)
	{
	  File const &file = background.get_sprite();
	  ITCP_protocol::Sprite	sprite = {file.get_name(), file.get_checksome(), background.get_id(), file.get_data(), file.get_size()};
	  m_itcp_protocol.send_give_sprite(sprite);
	  return;
	}
    }
}

void	Client::give_sprite(ITCP_protocol &itcp_protocol, ITCP_protocol::Sprite const &)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::list_meta_sounds(ITCP_protocol &itcp_protocol)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
  else
    {
      IGame const &game = m_server.get_game(get_login());
      std::list<ITCP_protocol::Sound *>	sounds;
      for (auto player : game.get_players())
	{
	  File const &file = player->get_sound();
	  sounds.push_back(new ITCP_protocol::Sound({file.get_name(), file.get_checksome(), player->get_id(), nullptr, static_cast<uint16_t>(file.get_size())}));
	}
      for (auto ientite : game.get_ientites())
	{
	  File const &file = ientite->get_sound();
	  sounds.push_back(new ITCP_protocol::Sound({file.get_name(), file.get_checksome(), ientite->get_id(), nullptr, static_cast<uint16_t>(file.get_size())}));
	}
      Background const   &background = game.get_background();
      File const &file = background.get_sound();
      sounds.push_back(new ITCP_protocol::Sound({file.get_name(), file.get_checksome(), background.get_id(), nullptr, static_cast<uint16_t>(file.get_size())}));
      m_itcp_protocol.send_meta_sounds(sounds);
      for (auto sound : sounds)
	delete sound;
    }
}

void	Client::meta_sounds(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Sound *> const &)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::take_sound(ITCP_protocol &itcp_protocol, ITCP_protocol::Sound const &sound)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
  else
    {
      IGame const &game = m_server.get_game(get_login());
      for (auto player : game.get_players())
	{
	  if (player->get_id() == sound.id)
	    {
	      File const &file = player->get_sound();
	      ITCP_protocol::Sound	sound = {file.get_name(), file.get_checksome(), player->get_id(), file.get_data(), file.get_size()};
	      m_itcp_protocol.send_give_sound(sound);
	      return;
	    }
	}
      for (auto ientite : game.get_ientites())
	{
	  if (ientite->get_id() == sound.id)
	    {
	      File const &file = ientite->get_sound();
	      ITCP_protocol::Sound	sound = {file.get_name(), file.get_checksome(), ientite->get_id(), file.get_data(), file.get_size()};
	      m_itcp_protocol.send_give_sound(sound);
	      return;
	    }
	}
      Background const   &background = game.get_background();
      if (background.get_id() == sound.id)
	{
	  File const &file = background.get_sound();
	  ITCP_protocol::Sound	sound = {file.get_name(), file.get_checksome(), background.get_id(), file.get_data(), file.get_size()};
	  m_itcp_protocol.send_give_sound(sound);
	  return;
	}
    }
}

void	Client::give_sound(ITCP_protocol &itcp_protocol, ITCP_protocol::Sound const &)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::ready(ITCP_protocol &itcp_protocol, bool ready)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
  m_ready = ready;
}

void	Client::start(ITCP_protocol &itcp_protocol, uint8_t, uint16_t)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::end(ITCP_protocol &itcp_protocol, uint64_t, bool)
{
  itcp_protocol.send_result(ITCP_protocol::IGNORED);
}

void	Client::leave(ITCP_protocol &itcp_protocol)
{
  if (m_login.size() == 0)
    itcp_protocol.send_result(ITCP_protocol::IGNORED);
  else
    m_server.leave_game(get_login());
}

std::string const	&Client::get_login(void) const
{
  return (m_login);
}

bool	Client::get_ready(void) const
{
  return (m_ready);
}

void	Client::start(uint8_t second, uint16_t port)
{
  m_itcp_protocol.send_start(second, port);
}

void	Client::end(uint64_t score, bool winner)
{
  m_itcp_protocol.send_end(score, winner);
}
