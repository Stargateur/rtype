//
// TCP_packet_send.cpp for TCP_packet_send in /home/plasko_a/projet/cplusplus/rtype/source/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 04:07:41 2015 Antoine Plaskowski
// Last update Tue Dec  8 16:31:29 2015 Antoine Plaskowski
//

#include	<iostream>
#include	"TCP_packet_send.hpp"

TCP_packet_send::TCP_packet_send(void) :
  m_send(0),
  m_send_data(0),
  m_is_send(false)
{
}

TCP_packet_send::~TCP_packet_send(void)
{
}

bool	TCP_packet_send::send(ITCP_client const &socket)
{
  if (m_send >= sizeof(m_buffer))
    return (true);
  uintmax_t	ret = socket.send(m_buffer[m_send], m_size_header + get_size() - m_send);

  if (ret == 0)
    return (true);
  m_send += ret;
  if (m_send < m_size_header + get_size())
    return (false);
  m_is_send = true;
  return (m_send != m_size_header + get_size());
}

bool	TCP_packet_send::put_string(std::string const &string)
{
  if (string.size() > UINT8_MAX)
    return (true);
  if (put_int<uint8_t>(static_cast<uint8_t>(string.size())))
    return (true);
  for (uintmax_t i = 0; i < string.size(); i++)
    if (put_int<uint8_t>(static_cast<uint8_t>(string[i])) == true)
      return (true);
  return (false);
}

bool	TCP_packet_send::is_send(void) const
{
  return (m_is_send);
}

void	TCP_packet_send::set_opcode(Opcode opcode)
{
  m_packet.opcode = opcode;
}

void	TCP_packet_send::set_size(void)
{
  m_packet.size = m_send_data;
}

void	TCP_packet_send::reset(void)
{
  m_send = 0;
  m_send_data = 0;
  m_is_send = false;
}
