//
// main.cpp for main in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 16 02:08:18 2015 Anthony Bury
// Last update Fri Dec 25 16:21:17 2015 Alaric Degand
//

#if				defined _WIN32 || defined _WIN64
# include <io.h>
# include <Windows.h>
#else
# include <unistd.h>
#endif

#include <cstring>
#include "View.hpp"

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#else
int	main(void)
#endif
{
  View billy(800, 600);
 	if (!billy.init())
		return (1);
	billy.loop();
	return (0);
}
