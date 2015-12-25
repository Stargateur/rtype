//
// IUDP_protocol.hpp for IUDP_protocol in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:35:29 2015 Antoine Plaskowski
// Last update Fri Dec 25 18:48:45 2015 Antoine Plaskowski
//

#ifndef		IUDP_PROTOCOL_HPP_
# define	IUDP_PROTOCOL_HPP_

# include	<cstdint>
# include	<string>
# include	<list>
# include	"ITime.hpp"
# include	"IUDP_client.hpp"
# include	"UDP_packet_recv.hpp"
# include	"UDP_packet_send.hpp"

class	IUDP_protocol
{
public:
  struct	Sprite
  {
    uint8_t	id;
    int64_t	x;
    int64_t	y;
    double	rotation;
  };
  struct	Sound
  {
    uint8_t	id;
  };
  struct	Input
  {
    bool	up;
    bool	down;
    bool	left;
    bool	right;
    bool	shot;
    bool	bomb;
  };
  class	Callback
  {
  public:
    virtual ~Callback(void);
    virtual void	sprites(IUDP_protocol &iudp_protocol, std::string const &login, std::list<Sprite *> const &sprites) = 0;
    virtual void	sounds(IUDP_protocol &iudp_protocol, std::string const &login, std::list<Sound *> const &sounds) = 0;
    virtual void	input(IUDP_protocol &iudp_protocol, std::string const &login, Input const &input) = 0;
  };
  enum  Error : uint8_t
  {
    VERSION,
    NONE
  };
public:
  virtual ~IUDP_protocol(void);
  virtual bool	want_send(void) const = 0;
  virtual bool	want_recv(void) const = 0;
  virtual void	send(IUDP_client const &socket) = 0;
  virtual void	recv(IUDP_client const &socket) = 0;
  virtual void	send_sprites(std::string const &login, std::list<Sprite *> const &sprites) = 0;
  virtual void	send_sounds(std::string const &login, std::list<Sound *> const &sounds) = 0;
  virtual void	send_input(std::string const &login, Input const &input) = 0;
};

#endif		/* !IUDP_PROTOCOL_HPP_ */
