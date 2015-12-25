//
// BasicGame.cpp for BasicGame in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 10:14:54 2015 Alaric Degand
// Last update Fri Dec 25 11:47:10 2015 Antoine Plaskowski
//

#include	"BasicGame.hpp"

#include	<unistd.h>

BasicGame::BasicGame(std::string const &owner, Usine<fct_new_ientite> &usine, std::string const &name, PortGenerator &port_generator) :
  m_owner(owner),
  m_name(name),
  m_usine(usine),
  m_port(port_generator),
  m_iudp_server(*new UDP_server(m_port.get_port()))
{
}

BasicGame::~BasicGame(void)
{
  delete &m_iudp_server;
}

void		BasicGame::run(void)
{
}
