//
// main.cpp for main in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Mon Nov 16 02:08:18 2015 Anthony Bury
// Last update Wed Dec 23 13:33:23 2015 Kevin Costa
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
#include "View.hpp"

#ifdef WIN32
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#else
int	main(void)
#endif
{
	View billy;
 	if (!billy.init())
		return (1);
	billy.loop();
	return (0);
}
