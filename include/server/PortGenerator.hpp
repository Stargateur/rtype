//
// PortGenerator.hpp for PortGenerator in /home/degand_a/Projects/rtype/include/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 13:17:09 2015 Alaric Degand
// Last update Tue Dec 22 15:16:28 2015 Alaric Degand
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
};

#endif		/* !PORTGENERATOR_HPP_ */
