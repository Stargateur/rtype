//
// Sprite.cpp for Sprite in /home/plasko_a/projet/cplusplus/rtype/source
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Dec 22 23:15:40 2015 Antoine Plaskowski
// Last update Tue Dec 22 23:48:59 2015 Antoine Plaskowski
//

#include	<exception>
#include	<fstream>
#include	<iostream>
#include	"Sprite.hpp"

Sprite::Sprite(std::string const &path) :
  m_name(path.substr(path.find_last_of("\\/")))
{
  std::ifstream	file(path, std::ios::in | std::ios::binary | std::ios::ate);

  if (file.is_open() == false)
    throw std::exception();
  m_size = file.tellg();
  m_data = new uint8_t [m_size];
  file.seekg(0, std::ios::beg);
  file.read(reinterpret_cast<char *>(m_data), m_size);
}

Sprite::~Sprite(void)
{
  delete m_data;
}

std::string const	&Sprite::get_name(void) const
{
  return (m_name);
}

uint8_t const	*Sprite::get_data(void) const
{
  return (m_data);
}

uintmax_t	Sprite::get_size(void) const
{
  return (m_size);
}
