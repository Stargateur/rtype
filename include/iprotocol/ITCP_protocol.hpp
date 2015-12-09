//
// ITCP_protocol.hpp for ITCP_protocol in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:35:29 2015 Antoine Plaskowski
// Last update Wed Dec  9 02:57:30 2015 Antoine Plaskowski
//

#ifndef		ITCP_PROTOCOL_HPP_
# define	ITCP_PROTOCOL_HPP_

# include	<cstdint>
# include	<string>
# include	"ITime.hpp"
# include	"ITCP_client.hpp"
# include	"TCP_packet_recv.hpp"
# include	"TCP_packet_send.hpp"

class	ITCP_protocol
{
public:
  struct	callback
  {
    void	(&result)(bool ready);
    void	(&connect)(std::string const &login, std::string const &password);
    void	(&disconnect)(void);
    void	(&ping)(void);
    void	(&pong)(void);
    void	(&list_games)(void);
    //  void	(&meta_games)(std::list<Game *> const &games);
    void	(&create_game)(void);
    void	(&join_game)(std::string const &game);
    void	(&message)(std::string const &login, std::string const &message);
    void	(&list_modes)(void);
    //  void	(&modes)(std::list<Mode *> const &modes);
    void	(&change_mode)(std::string const &mode);
    void	(&list_params)(void);
    //  void	(&params)(std::list<Param *> const&params);
    void	(&change_param)(std::string const &param, std::string const &value);
    void	(&list_meta_sprites)(void);
    //  void	(&meta_sprites)(std::list<Sprite *> const &sprites);
    //  void	(&take_sprite)(Sprite const &sprite);
    //  void	(&give_sprite)(Sprite const &sprite);
    void	(&list_meta_sounds)(void);
    //  void	(&meta_sounds)(std::list<Sound *> const &sounds);
    //  void	(&take_sound)(Sound const &sound);
    //  void	(&give_sound)(Sound const &sound);
    void	(&ready)(bool ready);
    void	(&start)(uint8_t second, uint16_t port);
    void	(&end)(uint64_t score, bool winner);
    void	(&leave)(void);
  };
  enum  Error : uint8_t
  {
    VERSION,
    NONE
  };
  
public:
  virtual ~ITCP_protocol(void);
  virtual bool	want_send(void) const = 0;
  virtual bool	want_recv(void) const = 0;
  virtual void	send(ITCP_client const &socket) = 0;
  virtual void	recv(ITCP_client const &socket) = 0;
  virtual void	send_result(Error error) = 0;
  virtual void	send_connect(std::string const &login, std::string const &password) = 0;
  virtual void	send_disconnect(void) = 0;
  virtual void	send_ping(void) = 0;
  virtual void	send_pong(void) = 0;
  virtual void	send_list_games(void) = 0;
  //  virtual void	send_games(std::list<Game *> const &games) = 0;
  virtual void	send_create_game(void) = 0;
  virtual void	send_join_game(std::string const &game) = 0;
  virtual void	send_message(std::string const &login, std::string const &message) = 0;
  virtual void	send_list_modes(void) = 0;
  //  virtual void	send_modes(std::list<Mode *> const &modes) = 0;
  virtual void	send_change_mode(std::string const &mode) = 0;
  virtual void	send_list_params(void) = 0;
  //  virtual void	send_params(std::list<Param *> const&params);
  virtual void	send_change_param(std::string const &param, std::string const &value) = 0;
  virtual void	send_list_meta_sprites(void) = 0;
  //  virtual void	send_meta_sprites(std::list<Sprite *> const &sprites) = 0;
  //  virtual void	send_take_sprite(Sprite const &sprite) = 0;
  //  virtual void	send_give_sprite(Sprite const &sprite) = 0;
  virtual void	send_list_meta_sounds(void) = 0;
  //  virtual void	send_meta_sounds(std::list<Sound *> const &sounds) = 0;
  //  virtual void	send_take_sound(Sound const &sound) = 0;
  //  virtual void	send_give_sound(Sound const &sound) = 0;
  virtual void	send_ready(bool ready) = 0;
  virtual void	send_start(uint8_t second, uint16_t port) = 0;
  virtual void	send_end(uint64_t score, bool winner) = 0;
  virtual void	send_leave(void) = 0;
};

#endif		/* !ITCP_PROTOCOL_HPP_ */
