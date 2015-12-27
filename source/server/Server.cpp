//
// Server.cpp for Server in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Sun Dec  6 03:15:49 2015 Alaric Degand
// Last update Sun Dec 27 02:48:56 2015 Antoine Plaskowski
//

#include	<iostream>
#include	"Client.hpp"
#include	"Server.hpp"
#include	"ASocket.hpp"

Server::Server(Option const &option) :
  m_itcp_server(*new TCP_server(option.get_opt("port"))),
  m_istandard(*new Standard(IStandard::In)),
  m_iselect(*new Select()),
  m_usine(option.get_zero().substr(0, option.get_zero().find_last_of("\\/")), NAME_FCT_NEW_IENTITE)
{
}

Server::~Server(void)
{
  delete &m_iselect;
  delete &m_istandard;
  delete &m_itcp_server;
}

void		Server::run(void)
{
  bool	g_keep_running = true;

  while (g_keep_running == true)
    {
      m_iselect.want_read(m_istandard);
      m_iselect.want_read(m_itcp_server);
      for (auto client : m_clients)
	client->pre_run(m_iselect);
      m_iselect.select();
      if (m_iselect.can_read(m_itcp_server))
	m_clients.push_back(new Client(*this, m_itcp_server.accept()));
      if (m_iselect.can_read(m_istandard))
	{
	  uint8_t	buffer[42];

	  if (m_istandard.read(buffer[0], 42) == 0)
	    g_keep_running = false;
	}
      for (auto it = m_clients.begin(); it != m_clients.end();)
	{
	  try
	    {
	      (*it)->run(m_iselect);
	      it++;
	    }
	  catch (...)
	    {
	      it = m_clients.erase(it);
	    }
	}
    }
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
