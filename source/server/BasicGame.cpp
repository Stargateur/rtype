//
// BasicGame.cpp for BasicGame in /home/degand_a/Projects/rtype/source/server
// 
// Made by Alaric Degand
// Login   <alaric.degand@epitech.eu>
// 
// Started on  Tue Dec 22 10:14:54 2015 Alaric Degand
// Last update Tue Dec 22 12:03:36 2015 Alaric Degand
//

#include	"BasicGame.hpp"

#include	<unistd.h>

BasicGame::BasicGame()
{
  _GameEnd = false;
}

BasicGame::~BasicGame()
{
}

void		BasicGame::loop(void)
{
  while (_GameEnd == false)
    {
      sleep(1);
      _GameEnd = true;
    }
}
