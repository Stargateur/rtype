//
// ATCP_packet.hpp for ATCP_packet in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:57:06 2015 Antoine Plaskowski
// Last update Sun Dec  6 03:59:46 2015 Antoine Plaskowski
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
    RESULT = 0,
    MAC_ADDRESS = 1,
    VERSION = 2,
    CONNECT = 3,
    DISCONNECT = 4,
    SERVERCMD = 5,
    CLIENTLOG = 6,
    PING = 7,
    PONG = 8,
    KEYBOARD = 9,
    MOUSE = 10
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
  static const	uintmax_t	m_size_header = sizeof(Opcode) + sizeof(uint8_t) + sizeof(uint16_t);
};


#endif		/* !ATCP_PACKET_HPP_ */
