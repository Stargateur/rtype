//
// PortGenerator.hpp for PortGenerator in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 13:17:09 2015 Alaric Degand
// Last update Sun Dec 27 19:24:16 2015 Antoine Plaskowski
//

#ifndef		PORTGENERATOR_HPP_
# define	PORTGENERATOR_HPP_

#include	<vector>

class		PortGenerator
{
private:
  int16_t		_AddValue;
  std::vector<bool>    	_TabOfDisp;
public:
  PortGenerator(int16_t p_start, int16_t p_last);
  ~PortGenerator();
  int16_t	SeekPort(void);
  void	FreePort(int16_t port);
};

class	Port
{
public:
  Port(PortGenerator &port_generator);
  ~Port(void);
  std::string const	&get_str_port(void) const;
  int16_t	get_port(void) const;
private:
  PortGenerator	&m_port_generator;
  int16_t const	m_port;
  std::string const	m_port_str;
};

#endif		/* !PORTGENERATOR_HPP_ */
