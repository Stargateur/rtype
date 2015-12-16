//
// main.cpp for main in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 16 02:08:18 2015 Anthony Bury
// Last update Wed Dec  9 16:22:05 2015 Antoine Plaskowski
//

#if				defined _WIN32 || defined _WIN64
# ifndef		WIN32
#  define		WIN32
# endif
# include <io.h>
# include <Windows.h>
#else
# include <unistd.h>
#endif
#include <cstring>
#include "Core.hpp"
#include "RView.hpp"
#include "RButton.hpp"

#ifdef WIN32
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#else
int	main(void)
#endif
{
	Core billy;
	RButton *b1 = new RButton(50, 50, 200, 100, "b1");
	b1->setFillColor(sf::Color::Green);
	RButton *b2 = new RButton(400, 50, 200, 100, "b2");
	b2->setFillColor(sf::Color::Blue);
  	RButton *b3 = new RButton(50, 400, 200, 100, "b3");
	b3->setFillColor(sf::Color::Yellow);
  	RView *toto = new RView();
	toto->addRButton(b1);
	toto->addRButton(b2);
	toto->addRButton(b3);

	billy.init();
	billy.addView(toto);
	billy.loop();
}
