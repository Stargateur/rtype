//
// main.cpp for main in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 16 02:08:18 2015 Anthony Bury
// Last update Tue Nov 17 16:10:31 2015 Anthony Bury
//

#include "Graph.hpp"

int main(void)
{
  Graph game;

  if (!game.init())
    return (1);
  game.loop();
  return (0);
}
