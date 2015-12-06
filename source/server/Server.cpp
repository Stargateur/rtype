
//
// Server.cpp for Server in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:15:49 2015 Alaric Degand
// Last update Sun Dec  6 04:05:35 2015 Alaric Degand
//

#include	"Server.hpp"
#include	"ASocket.hpp"

Server::Server(std::string const &port) :
  m_itcp_server(*new TCP_server(port))
{
}

void		Server::run(void)
{
  m_itcp_server.want_read();
  ASocket::select();
  if (m_itcp_server.can_read())
    m_clients.push_back(new Client(m_itcp_server.accept()));
}
