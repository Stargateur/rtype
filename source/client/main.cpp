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
#include "Button.hpp"

#ifdef WIN32
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#else
int	main(void)
#endif
{
	Core billy;
	Button *b1 = new Button(50, 50, 200, 100, "b1");
	b1->setFillColor(sf::Color::Green);
	Button *b2 = new Button(400, 50, 200, 100, "b2");
	b2->setFillColor(sf::Color::Blue);
  	Button *b3 = new Button(50, 400, 200, 100, "b3");
	b3->setFillColor(sf::Color::Yellow);
  	RView *toto = new RView();
	toto->addButton(b1);
	toto->addButton(b2);
	toto->addButton(b3);

	billy.init();
	billy.addView(toto);
	billy.loop();
}
