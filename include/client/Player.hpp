#ifndef		PLAYER_HPP_
# define	PLAYER_HPP_

#include "IUDP_protocol.hpp"

class Player : public IUDP_protocol::Callback
{
public:
	Player();
	~Player();

public:
	void	sprites(IUDP_protocol &iudp_protocol, std::string const &login, std::list<IUDP_protocol::Sprite *> const &sprites);
	void	sounds(IUDP_protocol &iudp_protocol, std::string const &login, std::list<IUDP_protocol::Sound *> const &sounds);
	void	input(IUDP_protocol &iudp_protocol, std::string const &login, IUDP_protocol::Input const &input);
	void	sprites(IUDP_protocol &iudp_protocol, std::string const &login, std::list<IUDP_protocol::Sprite *> const &sprites, IUDP_server::u_sockaddr const &sockaddr, socklen_t len);
	void	sounds(IUDP_protocol &iudp_protocol, std::string const &login, std::list<IUDP_protocol::Sound *> const &sounds, IUDP_server::u_sockaddr const &sockaddr, socklen_t len);
	void	input(IUDP_protocol &iudp_protocol, std::string const &login, IUDP_protocol::Input const &input, IUDP_server::u_sockaddr const &sockaddr, socklen_t len);
};

#endif