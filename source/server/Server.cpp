//
// Server.cpp for Server in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:15:49 2015 Alaric Degand
// Last update Thu Dec 24 23:29:37 2015 Antoine Plaskowski
//

#include	<iostream>
#include	"Client.hpp"
#include	"Server.hpp"
#include	"ASocket.hpp"

Server::Server(Option const &option) :
  m_itcp_server(*new TCP_server(option.get_opt("port"))),
  m_iselect(*new Select()),
  m_usine(option.get_zero().substr(0, option.get_zero().find_last_of("\\/")), NAME_FCT_NEW_IENTITE)
{
}

void		Server::run(void)
{
  m_iselect.want_read(m_itcp_server);
  m_iselect.select();
  if (m_iselect.can_read(m_itcp_server))
    m_clients.push_back(new Client(*this, m_itcp_server.accept()));
}

bool		Server::check_login(std::string const &login, std::string const &passwd) const
{
  if (login != passwd)
    return (false);
  for (auto client : m_clients)
    if (login == client->get_login())
      return (false);
  return (true);
}

Client		*Server::get_client(std::string const &login) const
{
  for (auto client : m_clients)
    if (login == client->get_login())
      return (client);
  return (NULL);
}
