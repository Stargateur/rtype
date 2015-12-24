//
// DLL.cpp for DLL in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:28:36 2015 Antoine Plaskowski
// Last update Wed Dec 23 18:52:39 2015 Antoine Plaskowski
//

#include	<dlfcn.h>
#include	<iostream>
#include	<string>
#include	<exception>
#include	"DLL.hpp"

DLL::DLL(std::string const &name) :
  m_handle(dlopen(name.c_str(), RTLD_LAZY)),
  m_name(name)
{
  if (m_handle == NULL)
    {
      char *str = dlerror();

      if (str != NULL)
	std::cerr << str << std::endl;
      throw std::exception();
    }
}

DLL::~DLL(void)
{
  if (dlclose(m_handle) != 0)
    {
      char *str = dlerror();

      if (str != NULL)
	std::cerr << str << std::endl;
    }
}

std::string const	&DLL::get_name(void) const
{
  return (m_name);
}
