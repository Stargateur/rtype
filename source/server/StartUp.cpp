//
// StartUp.cpp for StartUp in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 23 10:54:44 2015 Anthony Bury
// Last update Mon Nov 23 12:47:37 2015 Anthony Bury
//

#include "StartUp.hpp"

StartUp::StartUp(const std::string &port) :
  m_tcp(new TCP_server(port)), m_end(false)
{
}

StartUp::~StartUp(void)
{
  delete (this->m_tcp);
}

void StartUp::loop(void)
{
  while (!this->m_end)
    {
      this->m_tcp->want_read();
      for (size_t i = 0; i < this->m_lobbyClients.size(); i++)
	{
	  this->m_lobbyClients[i]->want_read();
	  this->m_lobbyClients[i]->want_write();
	}
      ASocket::select(NULL);
      if (this->m_tcp->can_read())
	this->m_lobbyClients.push_back(&this->m_tcp->accept());
      else
	for (size_t i = 0; i < this->m_lobbyClients.size(); i++)
	  if (this->m_lobbyClients[i]->can_read())
	    {
	      
	    }
    }
}
