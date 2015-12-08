//
// ATCP_packet.cpp for ATCP_packet in /home/plasko_a/projet/cplusplus/rtype/source/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 04:04:29 2015 Antoine Plaskowski
// Last update Tue Dec  8 16:31:04 2015 Antoine Plaskowski
//

#include	"ATCP_packet.hpp"

ATCP_packet::~ATCP_packet(void)
{
}

ATCP_packet::Opcode	ATCP_packet::get_opcode(void) const
{
  return (m_packet.opcode);
}

uint16_t	ATCP_packet::get_size(void) const
{
  return (m_packet.size);
}

uint8_t	ATCP_packet::operator[](uint16_t idx) const
{
  return (m_packet.data[idx]);
}
