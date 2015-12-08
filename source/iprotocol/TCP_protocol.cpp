//
// TCP_protocol.cpp for TCP_protocol in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:40:34 2015 Antoine Plaskowski
// Last update Tue Dec  8 17:42:23 2015 Antoine Plaskowski
//

#include	"TCP_protocol.hpp"

TCP_protocol::TCP_protocol(ITCP_protocol::callback const &callback) :
  m_callback(callback)
{
}

TCP_protocol::~TCP_protocol(void)
{
}

void	TCP_protocol::result(ITCP_protocol::Error error)
{
}

void	TCP_protocol::connect(std::string const &login, std::string const &password, uint8_t version)
{
}

void	TCP_protocol::disconnect(void)
{
}

void	TCP_protocol::ping(void)
{
}

void	TCP_protocol::pong(void)
{
}

void	TCP_protocol::list_games(void)
{
}
//void	TCP_protocol::games(std::list<Game *> const &games)
void	TCP_protocol::create_game(void)
{
}

void	TCP_protocol::join_game(std::string const &game)
{
}

void	TCP_protocol::message(std::string const &login, std::string const &message)
{
}

void	TCP_protocol::list_modes(void)
{
}

//void	TCP_protocol::modes(std::list<Mode *> const &modes)
void	TCP_protocol::change_mode(std::string const &mode)
{
}

void	TCP_protocol::list_params(void)
{
}

//void	TCP_protocol::params(std::list<Param *> const&params)
void	TCP_protocol::change_param(std::string const &param, std::string const &value)
{
}

void	TCP_protocol::list_meta_sprites(void)
{
}

//void	TCP_protocol::meta_sprites(std::list<Sprite *> const &sprites)
//void	TCP_protocol::take_sprite(Sprite const &sprite)
//void	TCP_protocol::give_sprite(Sprite const &sprite)
void	TCP_protocol::list_meta_sounds(void)
{
}

//void	TCP_protocol::meta_sounds(std::list<Sound *> const &sounds)
//void	TCP_protocol::take_sound(Sound const &sound)
//void	TCP_protocol::give_sound(Sound const &sound)
void	TCP_protocol::ready(bool ready)
{
}

void	TCP_protocol::start(ITime const &time, uint16_t port)
{
}

void	TCP_protocol::end(uint64_t score, bool winner)
{
}

void	TCP_protocol::leave(void)
{
}

void	TCP_protocol::set_callback(ITCP_protocol::callback const &callback)
{
}
