//
// DLL.cpp for DLL in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:28:36 2015 Antoine Plaskowski
// Last update Thu Dec 24 11:54:38 2015 Antoine Plaskowski
//

#include	<dlfcn.h>
#include	<iostream>
#include	<string>
#include	<exception>
#include	"DLL.hpp"

DLL::DLL(std::string const &name) :
  m_handle(dlopen(name.c_str(), RTLD_NOW)),
  m_name(name)
{
  if (m_handle == NULL)
    {
      char *str = dlerror();

      if (str != NULL)
	throw std::logic_error(str);
      else
	throw std::logic_error("Unknow");
    }
}

DLL::~DLL(void)
{
  if (dlclose(m_handle) != 0)
    (void)dlerror();
}

std::string const	&DLL::get_name(void) const
{
  return (m_name);
}
