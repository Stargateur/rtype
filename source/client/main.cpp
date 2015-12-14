//
// main.cpp for main in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 16 02:08:18 2015 Anthony Bury
// Last update Wed Dec  9 16:22:05 2015 Antoine Plaskowski
//

#include <unistd.h>
#include <cstring>
#include "Core.hpp"
#include "RView.hpp"
#include "RButton.hpp"
#include "TCP_client.hpp"
#include "UDP_client.hpp"
#include "UDP_server.hpp"

int	main(void)
{
	Core billy;
	RButton *b1 = new RButton(50, 50, 200, 100, "b1");
	b1->setFillColor(sf::Color::Green);
	RButton *b2 = new RButton(400, 50, 200, 100, "b2");
	b2->setFillColor(sf::Color::Blue);
  	RButton *b3 = new RButton(50, 400, 200, 100, "b3");
	b3->setFillColor(sf::Color::Yellow);
	std::cout << "test" << std::endl;
  	RView *toto = new RView();
  	std::cout << "test2" << std::endl;
	toto->addRButton(b1);
	toto->addRButton(b2);
	toto->addRButton(b3);
  	std::cout << "test3" << std::endl;

	billy.init();
	billy.addView(toto);
  	std::cout << "test4" << std::endl;
	billy.loop();

  //  ITCP_client	&yolo = *new TCP_client("localhost", "4242");
  //while (42);
  // UDP_client	client("127.0.0.1", "4242");

  // uint8_t	toto[4242];
  // memcpy(toto, "bonjour", 7);
  // client.send(toto[0], 7);

  // uintmax_t ret = client.recv(toto[0], 4242);
  // write(1, toto, ret);
}
