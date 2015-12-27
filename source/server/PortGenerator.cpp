//
// PortGenerator.cpp for PortGenerator in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 13:19:44 2015 Alaric Degand
// Last update Fri Dec 25 11:44:32 2015 Antoine Plaskowski
//

#include	<algorithm>
#include	<exception>
#include	<stdexcept>
#include	<string>
#include	"PortGenerator.hpp"

PortGenerator::PortGenerator(int16_t p_start, int16_t p_last)
{
  if (p_start > p_last)
    std::swap(p_start, p_last);
  _TabOfDisp.resize(p_last - p_start, false);
  _AddValue = p_start;
}

PortGenerator::~PortGenerator()
{
}

int16_t	PortGenerator::SeekPort(void)
{
  for (uintmax_t i = 0; i < _TabOfDisp.size(); i++)
    {
      if (_TabOfDisp[i] == false)
	{
	  _TabOfDisp[i] = true;
	  return (i + _AddValue);
	}
    }
  throw std::logic_error("No Port available");
}

void	PortGenerator::FreePort(int16_t port)
{
  _TabOfDisp[port - _AddValue] = false;
}

Port::Port(PortGenerator &port_generator) :
  m_port_generator(port_generator),
  m_port(m_port_generator.SeekPort()),
  m_port_str(std::to_string(m_port))
{
}

Port::~Port(void)
{
  m_port_generator.FreePort(m_port);
}

std::string const	&Port::get_port(void) const
{
  return (m_port_str);
}
