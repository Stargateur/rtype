//
// ATCP_packet.hpp for ATCP_packet in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:57:06 2015 Antoine Plaskowski
// Last update Tue Dec  8 16:23:49 2015 Antoine Plaskowski
//

#ifndef		ATCP_PACKET_HPP_
# define	ATCP_PACKET_HPP_

# include	<cstdint>
# include	"ITCP_client.hpp"

class	ATCP_packet
{
public:
  enum  Opcode : uint8_t
  {
    Result = 0,
    Mac_address = 1,
    Version = 2,
    Connect = 3,
    Disconnect = 4,
    Servercmd = 5,
    Clientlog = 6,
    Ping = 7,
    Pong = 8,
    Keyboard = 9,
    Mouse = 10
  };
  virtual ~ATCP_packet(void);
  Opcode	get_opcode(void) const;
  uint8_t	get_id(void) const;
  uint16_t	get_size(void) const;
  uint8_t	operator[](uint16_t idx) const;
protected:
#pragma	pack(1)
    struct	s_packet
    {
      Opcode	opcode;
      uint8_t	id;
      uint16_t	size;
      uint8_t	data[UINT16_MAX];
    };
  union
  {
    s_packet	m_packet;
    uint8_t	m_buffer[sizeof(s_packet)];
  };
#pragma	pack()
  static const	uintmax_t	m_size_header = sizeof(m_packet) - sizeof(m_packet.data);
};


#endif		/* !ATCP_PACKET_HPP_ */
