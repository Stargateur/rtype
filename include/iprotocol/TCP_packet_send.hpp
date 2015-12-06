//
// TCP_packet_send.hpp for TCP_packet_send in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 04:02:59 2015 Antoine Plaskowski
// Last update Sun Dec  6 04:13:38 2015 Antoine Plaskowski
//

#ifndef		TCP_PACKET_SEND_HPP_
# define	TCP_PACKET_SEND_HPP_

# include	<limits>
# include	"ATCP_packet.hpp"

class	TCP_packet_send : public ATCP_packet
{
public:
  TCP_packet_send(void);
  template<typename T>
  bool	put_int(T const value)
  {
    for (uintmax_t i = 0; i < sizeof(T); i++)
      {
	m_packet.data[m_send_data] = (value >> (i * std::numeric_limits<uint8_t>::digits));
	if (m_send_data++ == UINT16_MAX)
	  return (true);
      }
    return (false);
  }
  bool	put_string(std::string const &string);
  bool	send(ITCP_client const &socket);
  bool	is_send(void) const;
  void	set_opcode(Opcode opcode);
  void	set_id(uint8_t id);
  void	set_size(void);
  void	reset(void);
private:
  uintmax_t	m_send;
  uint16_t	m_send_data;
  bool	m_is_send;
};

#endif		/* !TCP_PACKET_SEND_HPP_ */
