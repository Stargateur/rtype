//
// PortGenerator.cpp for PortGenerator in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 13:19:44 2015 Alaric Degand
// Last update Tue Dec 22 14:38:53 2015 Antoine Plaskowski
//

#include	<algorithm>
#include	<exception>
#include	<stdexcept>
#include	"PortGenerator.hpp"

PortGenerator::PortGenerator(int16_t p_start, int16_t p_last)
{
  if (p_start > p_last)
    std::swap(p_start, p_last);
  for (int16_t i = p_start; i < p_last; i++)
    {
      _vPort.push_back(i);
      _TabOfDisp.push_back(false);
    }
}

PortGenerator::~PortGenerator()
{
}

int16_t		PortGenerator::SeekPort(void)
{
  for (uint i = 0; i < _TabOfDisp.size(); i++)
    {
      if (_TabOfDisp[i] == false)
	{
	  _TabOfDisp[i] = true;
	  return (_vPort[i]);
	}
    }
  throw std::logic_error("No Port available");
}
