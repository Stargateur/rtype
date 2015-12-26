#include "Client.hpp"

Client::Client(ITCP_client &client)
{
}


Client::~Client()
{
}

void	Client::result(ITCP_protocol &itcp_protocol, ITCP_protocol::Error ready)
{
}

void	Client::connect(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &password)
{
}

void	Client::disconnect(ITCP_protocol &itcp_protocol)
{
}

void	Client::ping(ITCP_protocol &itcp_protocol)
{
	itcp_protocol.send_pong();
}

void	Client::pong(ITCP_protocol &itcp_protocol)
{
}

void	Client::list_meta_games(ITCP_protocol &itcp_protocol)
{
}

void	Client::meta_games(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Game *> const &games)
{
}

void	Client::create_game(ITCP_protocol &itcp_protocol, ITCP_protocol::Game const &game)
{

}

void	Client::join_game(ITCP_protocol &itcp_protocol, ITCP_protocol::Game const &game)
{
}

void	Client::message(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &message)
{
}

// void	Client::list_modes(ITCP_protocol &itcp_protocol)
// {
// }

// void	Client::meta_modes(ITCP_protocol &itcp_protocol, std::list<Mode *> const &modes)

// void	Client::change_mode(ITCP_protocol &itcp_protocol, std::string const &mode)
// {
// }

void	Client::list_meta_params(ITCP_protocol &itcp_protocol)
{
}

void	Client::meta_params(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Param *> const &params)
{
}

void	Client::change_param(ITCP_protocol &itcp_protocol, ITCP_protocol::Param const &param)
{
}

void	Client::list_meta_sprites(ITCP_protocol &itcp_protocol)
{
}

void	Client::meta_sprites(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Sprite *> const &sprites)
{
}

void	Client::take_sprite(ITCP_protocol &itcp_protocol, ITCP_protocol::Sprite const &sprite)
{
}

void	Client::give_sprite(ITCP_protocol &itcp_protocol, ITCP_protocol::Sprite const &sprite)
{
}

void	Client::list_meta_sounds(ITCP_protocol &itcp_protocol)
{
}

void	Client::meta_sounds(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Sound *> const &sounds)
{
}

void	Client::take_sound(ITCP_protocol &itcp_protocol, ITCP_protocol::Sound const &sound)
{
}

void	Client::give_sound(ITCP_protocol &itcp_protocol, ITCP_protocol::Sound const &sound)
{
}

void	Client::ready(ITCP_protocol &itcp_protocol, bool ready)
{
}

void	Client::start(ITCP_protocol &itcp_protocol, uint8_t second, uint16_t port)
{
}

void	Client::end(ITCP_protocol &itcp_protocol, uint64_t score, bool winner)
{
}

void	Client::leave(ITCP_protocol &itcp_protocol)
{
}
