//
// main.cpp for main in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 16 02:08:18 2015 Anthony Bury
// Last update Tue Dec  8 03:12:20 2015 Antoine Plaskowski
//

#include <unistd.h>
#include <iostream>
#include <cstring>
#include "Server.hpp"
#include "IUDP_server.hpp"
#include "UDP_server.hpp"
#include "UDP_client.hpp"

int main(int ac, char **av)
{
  UDP_server	server("4242");

  while (42)
    {
      server.want_read();
      ASocket::select();
      if (server.can_read())
	{
	  uint8_t	toto[4242];

	  IUDP_server::u_sockaddr	sockaddr;
	  socklen_t	len;
	  uintmax_t ret = server.recvfrom(toto[0], 4242, sockaddr, len);
	  write(1, toto, ret);
	  memcpy(toto, "bonjour", 7);
	  server.sendto(toto[0], 7, sockaddr, len);
	}
    }
  // Server	yololasuite("4242");
  // while (4242)
  //   {
  //     yololasuite.run();
  //   }
  // return (0);
}
