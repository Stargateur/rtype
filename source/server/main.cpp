//
// main.cpp for main in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 16 02:08:18 2015 Anthony Bury
// Last update Mon Nov 23 12:53:15 2015 Anthony Bury
//

#include <iostream>
#include "StartUp.hpp"

int main(int ac, char **av)
{
  StartUp *server;
  if (ac == 1)
    {
      std::cerr << "Missing argument" << std::endl;
      std::cerr << "Usage : " << av[0] << " PORT" << std::endl;
      return (1);
    }
  try
    {
      server = new StartUp(av[0]);
    }
  catch (const std::exception &error)
    {
      return (1);
    }
  server->loop();
  return (0);
}
