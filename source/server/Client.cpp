//
// Client.cpp for Client in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:56:02 2015 Alaric Degand
// Last update Sun Dec  6 04:07:54 2015 Alaric Degand
//

#include	"Client.hpp"

Client::Client(ITCP_client &itcp) :
  m_itcp_client(itcp)
{
}
