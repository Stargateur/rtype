#include "Player.hpp"

Player::Player()
{
}


Player::~Player()
{
}

void Player::sprites(IUDP_protocol & iudp_protocol, std::string const & login, std::list<IUDP_protocol::Sprite*> const & sprites)
{
}

void Player::sounds(IUDP_protocol & iudp_protocol, std::string const & login, std::list<IUDP_protocol::Sound*> const & sounds)
{
}

void Player::input(IUDP_protocol & iudp_protocol, std::string const & login, IUDP_protocol::Input const & input)
{
}

void Player::sprites(IUDP_protocol & iudp_protocol, std::string const & login, std::list<IUDP_protocol::Sprite*> const & sprites, IUDP_server::u_sockaddr const & sockaddr, socklen_t len)
{
}

void Player::sounds(IUDP_protocol & iudp_protocol, std::string const & login, std::list<IUDP_protocol::Sound*> const & sounds, IUDP_server::u_sockaddr const & sockaddr, socklen_t len)
{
}

void Player::input(IUDP_protocol & iudp_protocol, std::string const & login, IUDP_protocol::Input const & input, IUDP_server::u_sockaddr const & sockaddr, socklen_t len)
{
}
