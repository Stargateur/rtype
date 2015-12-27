#ifndef		CLIENT_HPP_
# define	CLIENT_HPP_

# include "ITCP_protocol.hpp"

class Network;
class Model;

class Client : public ITCP_protocol::Callback
{
public:
	Client(Network &, Model &);
	~Client(void);

public:
	void	result(ITCP_protocol &itcp_protocol, ITCP_protocol::Error ready);
	void	connect(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &password);
	void	disconnect(ITCP_protocol &itcp_protocol);
	void	ping(ITCP_protocol &itcp_protocol);
	void	pong(ITCP_protocol &itcp_protocol);
	void	list_meta_games(ITCP_protocol &itcp_protocol);
	void	meta_games(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Game *> const &games);
	void	create_game(ITCP_protocol &itcp_protocol, ITCP_protocol::Game const &game);
	void	join_game(ITCP_protocol &itcp_protocol, ITCP_protocol::Game const &game);
	void	message(ITCP_protocol &itcp_protocol, std::string const &login, std::string const &message);
	//  void	list_modes(ITCP_protocol &itcp_protocol);
	//  void	meta_modes(ITCP_protocol &itcp_protocol, std::list<Mode *> const &modes);
	//  void	change_mode(ITCP_protocol &itcp_protocol, std::string const &mode);
	void	list_meta_params(ITCP_protocol &itcp_protocol);
	void	meta_params(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Param *> const&params);
	void	change_param(ITCP_protocol &itcp_protocol, ITCP_protocol::Param const &param);
	void	list_meta_sprites(ITCP_protocol &itcp_protocol);
	void	meta_sprites(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Sprite *> const &sprites);
	void	take_sprite(ITCP_protocol &itcp_protocol, ITCP_protocol::Sprite const &sprite);
	void	give_sprite(ITCP_protocol &itcp_protocol, ITCP_protocol::Sprite const &sprite);
	void	list_meta_sounds(ITCP_protocol &itcp_protocol);
	void	meta_sounds(ITCP_protocol &itcp_protocol, std::list<ITCP_protocol::Sound *> const &sounds);
	void	take_sound(ITCP_protocol &itcp_protocol, ITCP_protocol::Sound const &sound);
	void	give_sound(ITCP_protocol &itcp_protocol, ITCP_protocol::Sound const &sound);
	void	ready(ITCP_protocol &itcp_protocol, bool ready);
	void	start(ITCP_protocol &itcp_protocol, uint8_t second, uint16_t port);
	void	end(ITCP_protocol &itcp_protocol, uint64_t score, bool winner);
	void	leave(ITCP_protocol &itcp_protocol);
	
private:
	Network &m_net;
	Model &m_model;
};

#endif