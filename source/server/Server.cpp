
//
// Server.cpp for Server in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:15:49 2015 Alaric Degand
// Last update Wed Dec  9 16:01:50 2015 Antoine Plaskowski
//

#include	<iostream>
#include	"Server.hpp"
#include	"ASocket.hpp"

Server::Server(std::string const &port) :
  m_itcp_server(*new TCP_server(port)),
  m_iselect(*new Select())
{
}

void		Server::run(void)
{
  m_iselect.want_read(m_itcp_server);
  m_iselect.select();
  if (m_iselect.can_read(m_itcp_server))
    {
      m_clients.push_back(new Client(*this, m_itcp_server.accept()));
      std::cout << "Glenn y meurt" << std::endl;
    }
}
