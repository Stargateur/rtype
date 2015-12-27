//
// File.hpp for File in /home/plasko_a/projet/cplusplus/rtype/include
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Tue Dec 22 23:15:52 2015 Antoine Plaskowski
// Last update Sun Dec 27 07:09:02 2015 Antoine Plaskowski
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
private:
  std::string const	m_name;
  uint8_t	*m_data;
  uintmax_t	m_size;
};

#endif		/* !FILE_HPP_ */
