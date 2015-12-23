//
// UDP_protocol.hpp for UDP_protocol in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:35:29 2015 Antoine Plaskowski
// Last update Tue Dec 22 22:13:10 2015 Antoine Plaskowski
//

#ifndef		UDP_PROTOCOL_HPP_
# define	UDP_PROTOCOL_HPP_

# include	<cstdint>
# include	<string>
# include	<array>
# include	"IUDP_protocol.hpp"
# include	"ISelect.hpp"

class	UDP_protocol : public IUDP_protocol
{
public:
  UDP_protocol(IUDP_protocol::Callback &callback);
  ~UDP_protocol(void);
private:
  UDP_packet_send	&get_to_send(void);
  void	set_to_send(UDP_packet_send *to_send, AUDP_packet::Opcode opcode);
  //  void	set_callback(IUDP_protocol::Callback &callback);
public:
  bool	want_send(void) const;
  bool	want_recv(void) const;
  void	send(IUDP_client const &socket);
  void	recv(IUDP_client const &socket);
  void	send_sprites(std::list<IUDP_protocol::Sprite *> const &sprites);
  void	send_sounds(std::list<IUDP_protocol::Sound *> const &sounds);
  void	send_input(IUDP_protocol::Input const &inputs);
private:
  void	recv_sprites(void);
  void	recv_sounds(void);
  void	recv_input(void);
private:
  IUDP_protocol::Callback	&m_callback;
  UDP_packet_recv	m_to_recv;
  std::list<UDP_packet_send *>	m_to_send;
};

#endif		/* !UDP_PROTOCOL_HPP_ */
