//
// ITCP_protocol.hpp for ITCP_protocol in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:35:29 2015 Antoine Plaskowski
// Last update Mon Dec  7 15:38:04 2015 Antoine Plaskowski
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
      VERSION,
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
  virtual void	list_meta_sprites(void) = 0;
  //  virtual void	meta_sprites(std::list<Sprite *> const &sprites) = 0;
  //  virtual void	take_sprite(Sprite const &sprite) = 0;
  //  virtual void	give_sprite(Sprite const &sprite) = 0;
  virtual void	list_meta_sounds(void) = 0;
  //  virtual void	meta_sounds(std::list<Sound *> const &sounds) = 0;
  //  virtual void	take_sound(Sound const &sound) = 0;
  //  virtual void	give_sound(Sound const &sound) = 0;
  virtual void	ready(bool ready) = 0;
  virtual void	start(ITime const &time, uint16_t port) = 0;
  virtual void	end(uint64_t score, bool winner) = 0;
  virtual void	leave(void) = 0;
  virtual void	set_result(void (&result)(Error error)) = 0;
  virtual void	set_connect(void (&connect)(std::string const &login, std::string const &password, uint8_t version)) = 0;
  virtual void	set_disconnect(void (&disconnect)(void)) = 0;
  virtual void	set_ping(void (&ping)(void)) = 0;
  virtual void	set_pong(void (&pong)(void)) = 0;
  virtual void	set_list_meta_games(void (&list_games)(void)) = 0;
  //  virtual void	set_meta_games(void (&games)(std::list<Game *> const &games)) = 0;
  virtual void	set_create_game(void (&create_game)(void)) = 0;
  virtual void	set_join_game(void (&join_game)(std::string const &game)) = 0;
  virtual void	set_message(void (&message)(std::string const &login, std::string const &message)) = 0;
  virtual void	set_list_modes(void (&list_modes)(void)) = 0;
  //  virtual void	set_modes(void (&modes)(std::list<Mode *> const &modes)) = 0;
  virtual void	set_change_mode(void (&change_mode)(std::string const &mode)) = 0;
  virtual void	set_list_params(void (&list_params)(void)) = 0;
  //  virtual void	set_params(void (&params)(std::list<Param *> const&params)) = 0;
  virtual void	set_change_param(void (&change_param)(std::string const &param, std::string const &value)) = 0;
  virtual void	set_list_meta_sprites(void (&list_meta_sprite)(void)) = 0;
  //  virtual void	set_meta_sprites(void (&meta_sprites)(std::list<Sprite *> const &sprites)) = 0;
  //  virtual void	set_take_sprite(void (&take_sprite)(Sprite const &sprite)) = 0;
  //  virtual void	set_give_sprite(void (&give_sprite)(Sprite const &sprite)) = 0;
  virtual void	set_list_meta_sounds(void (&list_meta_sound)(void)) = 0;
  //  virtual void	set_meta_sounds(void (&meta_sounds)(std::list<Sound *> const &sounds)) = 0;
  //  virtual void	set_take_sound(void (&sound)(Sound const &sound)) = 0;
  //  virtual void	set_give_sound(void (&sound)(Sound const &sound)) = 0;
  virtual void	set_ready(void (&ready)(bool ready)) = 0;
  virtual void	set_start(void (&start)(ITime const &time, uint16_t port)) = 0;
  virtual void	set_end(void (&end)(uint64_t score, bool winner)) = 0;
  virtual void	set_leave(void (&leave)(void)) = 0;
};

#endif		/* !ITCP_PROTOCOL_HPP_ */
