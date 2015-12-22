//
// UDP_packet_recv.cpp for UDP_packet_recv in /home/plasko_a/projet/cplusplus/rtype/source/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 04:05:19 2015 Antoine Plaskowski
// Last update Tue Dec 22 16:46:35 2015 Antoine Plaskowski
//

#include	<iostream>
#include	"UDP_packet_recv.hpp"

UDP_packet_recv::UDP_packet_recvfrom(void) :
  AUDP_packet(),
  m_recv(0)
{
}

UDP_packet_recv::~UDP_packet_recvfrom(void)
{
}

bool	UDP_packet_recv::recvfrom(IUDP_client const &socket)
{
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
  set_size(0);
  m_recv = 0;
  return (m_recv != m_size_header + get_size());
}

void	UDP_packet_recv::get(std::string &string)
{
  uint8_t       size;

  get(size);
  for (uintmax_t i = 0; i < size; i++)
    {
      uint8_t   c;
      get(c);
      string.push_back(static_cast<char>(c));
    }
}
