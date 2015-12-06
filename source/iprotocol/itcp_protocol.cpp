//
// itcp_protocol.cpp for itcp_protocol in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:40:34 2015 Antoine Plaskowski
// Last update Sun Dec  6 03:42:23 2015 Antoine Plaskowski
//

#include	"itcp_protocol.hpp"

ITCP_protocol::ITCP_protocol(ISocket const &isocket) :
  m_isocket(isocket)
{
}

ITCP_protocol::~ITCP_protocol(void)
{
  delete &m_isocket;
}
