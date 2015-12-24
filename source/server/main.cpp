//
// main.cpp for main in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 16 02:08:18 2015 Anthony Bury
// Last update Thu Dec 24 13:32:34 2015 Antoine Plaskowski
//

#include <unistd.h>
#include <iostream>
#include <cstring>
#include "Server.hpp"
#include "IUDP_server.hpp"
#include "UDP_server.hpp"
#include "UDP_client.hpp"
#include "Select.hpp"
#include "BasicGame.hpp"

int	main(int argc, char **argv)
{
  Option	option;

  option.add_opt("port", "this is the port of tcp server", "4242");
  option.parse_opt(argc, argv);
  Server	server(option);
  return (0);
}
