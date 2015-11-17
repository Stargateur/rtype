//
// main.cpp for main in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 16 02:08:18 2015 Anthony Bury
// Last update Tue Nov 17 12:29:22 2015 Anthony Bury
//

#include "Game.hpp"

int main(void)
{
  Game game;

  if (!game.init())
    return (1);
  game.loop();
  return (0);
}
