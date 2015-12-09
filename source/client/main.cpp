//
// main.cpp for main in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 16 02:08:18 2015 Anthony Bury
// Last update Wed Dec  9 14:47:10 2015 Antoine Plaskowski
//

#include	<unistd.h>
#include	<cstring>
#include	"TCP_client.hpp"
#include	"UDP_client.hpp"
#include	"UDP_server.hpp"

int	main(void)
{
  // ITCP_client	&yolo = *new TCP_client("localhost", "4242");
  // while (42);
  UDP_client	client("127.0.0.1", "4242");

  uint8_t	toto[4242];
  memcpy(toto, "bonjour", 7);
  client.send(toto[0], 7);

  uintmax_t ret = client.recv(toto[0], 4242);
  write(1, toto, ret);
}
