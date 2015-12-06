//
// ITCP_protocol.hpp for ITCP_protocol in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:35:29 2015 Antoine Plaskowski
// Last update Sun Dec  6 06:48:33 2015 Antoine Plaskowski
//

#ifndef		ITCP_PROTOCOL_HPP_
# define	ITCP_PROTOCOL_HPP_

# include	<cstdint>
# include	<string>
# include	"ITime.hpp"

class	ITCP_protocol
{
public:
  enum	Error : uint8_t
    {
      NONE
    };
public:
  virtual ~ITCP_protocol(void);
  virtual void	result(Error error) = 0;
  virtual void	connect(std::string const &login, std::string const &password, uint8_t version) = 0;
  virtual void	disconnect(void) = 0;
  virtual void	ping(void) = 0;
  virtual void	pong(void) = 0;
  virtual void	list_games(void) = 0;
  //  virtual void	games(std::list<Game *> const &games) = 0;
  virtual void	create_game(void) = 0;
  virtual void	join_game(std::string const &game) = 0;
  virtual void	message(std::string const &login, std::string const &message) = 0;
  virtual void	list_modes(void) = 0;
  //  virtual void	modes(std::list<Mode *> const &modes) = 0;
  virtual void	change_mode(std::string const &mode) = 0;
  virtual void	list_params(void) = 0;
  //  virtual void	params(std::list<Param *> const&params);
  virtual void	change_param(std::string const &param, std::string const &value) = 0;
  virtual void	list_sprite(void) = 0;
  //virtual void	sprites(std::list<Sprite *> const &sprites) = 0;
  //  virtual void	sprite(Sprite const &sprite) = 0;
  virtual void	list_sound(void) = 0;
  //virtual void	sounds(std::list<Sound *> const &sounds) = 0;
  //  virtual void	sound(Sound const &sound) = 0;
  virtual void	ready(bool ready) = 0;
  virtual void	start(ITime const &time) = 0;
  virtual void	end(uint64_t score, bool winner) = 0;
  virtual void	leave(void) = 0;
  virtual void	set_result(void (&result)(Error error)) = 0;
  virtual void	set_connect(void (&connect)(std::string const &login, std::string const &password, uint8_t version)) = 0;
  virtual void	set_disconnect(void (&disconnect)(void)) = 0;
  virtual void	set_ping(void (&ping)(void)) = 0;
  virtual void	set_pong(void (&pong)(void)) = 0;
  virtual void	set_list_games(void (&list_games)(void)) = 0;
  //  virtual void	set_games(void (&games)(std::list<Game *> const &games)) = 0;
  virtual void	set_create_game(void (&create_game)(void)) = 0;
  virtual void	set_join_game(void (&join_game)(std::string const &game)) = 0;
  virtual void	set_message(void (&message)(std::string const &login, std::string const &message)) = 0;
  virtual void	set_list_modes(void (&list_modes)(void)) = 0;
  //  virtual void	set_modes(void (&modes)(std::list<Mode *> const &modes)) = 0;
  virtual void	set_change_mode(void (&change_mode)(std::string const &mode)) = 0;
  virtual void	set_list_params(void (&list_params)(void)) = 0;
  //  virtual void	set_params(void (&params)(std::list<Param *> const&params)) = 0;
  virtual void	set_change_param(void (&change_param)(std::string const &param, std::string const &value)) = 0;
  virtual void	set_list_sprite(void (&list_sprite)(void)) = 0;
  //virtual void	set_sprites(void (&sprites)(std::list<Sprite *> const &sprites)) = 0;
  //  virtual void	set_sprite(void (&sprite)(Sprite const &sprite)) = 0;
  virtual void	set_list_sound(void (&list_sound)(void)) = 0;
  //virtual void	set_sounds(void (&sounds)(std::list<Sound *> const &sounds)) = 0;
  //  virtual void	set_sound(void (&sound)(Sound const &sound)) = 0;
  virtual void	set_ready(void (&ready)(bool ready)) = 0;
  virtual void	set_start(void (&start)(ITime const &time)) = 0;
  virtual void	set_end(void (&end)(uint64_t score, bool winner)) = 0;
  virtual void	set_leave(void (&leave)(void)) = 0;
};

#endif		/* !ITCP_PROTOCOL_HPP_ */
