//
// TCP_packet_recv.cpp for TCP_packet_recv in /home/plasko_a/projet/cplusplus/rtype/source/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 04:05:19 2015 Antoine Plaskowski
// Last update Sun Dec  6 05:35:25 2015 Antoine Plaskowski
//

#include	<iostream>
#include	"TCP_packet_recv.hpp"

TCP_packet_recv::TCP_packet_recv(void) :
  m_recv(0),
  m_recv_data(0),
  m_is_recv(false)
{
}

TCP_packet_recv::~TCP_packet_recv(void)
{
}

bool	TCP_packet_recv::recv(ITCP_client const &socket)
{
  if (m_recv >= sizeof(m_buffer))
    return (true);
  uintmax_t	ret;
  if (m_recv < m_size_header)
    ret = socket.recv(m_buffer[m_recv], m_size_header - m_recv);
  else
    ret = socket.recv(m_buffer[m_recv], m_size_header + get_size() - m_recv);
  if (ret == 0)
    return (true);
  m_recv += ret;
  if (m_recv < m_size_header)
    return (false);
  if (m_recv < m_size_header + get_size())
    return (false);
  m_is_recv = true;
  return (m_recv != m_size_header + get_size());
}

bool	TCP_packet_recv::get_string(std::string &string)
{
  uint8_t       size;

  string.erase();
  if (get_int<uint8_t>(size) == true)
    return (true);
  for (uintmax_t i = 0; i < size; i++)
    {
      uint8_t   c;
      if (get_int<uint8_t>(c) == true)
	return (true);
      string.push_back(c);
    }
  return (false);
}

bool	TCP_packet_recv::is_recv(void) const
{
  return (m_is_recv);
}

void	TCP_packet_recv::reset(void)
{
  m_recv = 0;
  m_recv_data = 0;
  m_is_recv = false;
}
