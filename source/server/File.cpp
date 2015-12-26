//
// File.cpp for File in /home/plasko_a/projet/cplusplus/rtype/source
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Dec 22 23:15:40 2015 Antoine Plaskowski
// Last update Sat Dec 26 15:37:17 2015 Antoine Plaskowski
//

#include	<exception>
#include	<fstream>
#include	<iostream>
#include	"File.hpp"

uint8_t	File::m_id_max = 0;
std::list<File *>	File::m_files;

File::File(std::string const &path) :
  m_name(path.substr(path.find_last_of("\\/"))),
  m_id(m_id_max++)
{
  std::ifstream	file(path, std::ios::in | std::ios::binary | std::ios::ate);

  if (file.is_open() == false)
    throw std::logic_error(path + " : can't open");
  m_size = file.tellg();
  m_data = new uint8_t [m_size];
  file.seekg(0, std::ios::beg);
  file.read(reinterpret_cast<char *>(m_data), m_size);
  m_files.push_back(this);
  std::cout << "coucou" << std::endl;
}

File::~File(void)
{
  m_files.remove(this);
  delete m_data;
}

std::string const	&File::get_name(void) const
{
  return (m_name);
}

uint8_t const	*File::get_data(void) const
{
  return (m_data);
}

uintmax_t	File::get_size(void) const
{
  return (m_size);
}

uint8_t	File::get_id(void) const
{
  return (m_size);
}

std::list<File *> const	&File::get_files(void) const
{
  return (m_files);
}
