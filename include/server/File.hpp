//
// File.hpp for File in /home/plasko_a/projet/cplusplus/rtype/include
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Dec 22 23:15:52 2015 Antoine Plaskowski
// Last update Sat Dec 26 15:36:56 2015 Antoine Plaskowski
//

#ifndef		FILE_HPP_
# define	FILE_HPP_

# include	<string>
# include	<cstdint>
# include	<list>

class	File
{
public:
  File(std::string const &path);
  ~File(void);
  std::string const	&get_name(void) const;
  uint8_t const	*get_data(void) const;
  uintmax_t	get_size(void) const;
  uint8_t	get_id(void) const;
  std::list<File *> const	&get_files(void) const;
private:
  static uint8_t	m_id_max;
  static std::list<File *>	m_files;
  std::string const	m_name;
  uint8_t	*m_data;
  uintmax_t	m_size;
  uintmax_t	m_id;
};

#endif		/* !FILE_HPP_ */
