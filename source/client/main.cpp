//
// main.cpp for main in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 16 02:08:18 2015 Anthony Bury
// Last update Sun Dec  6 04:37:23 2015 Alaric Degand
//

#include "TCP_client.hpp"

int main(void)
{
  ITCP_client	&yolo = *new TCP_client("localhost", "4242");
  while (42);
}
