//
// Usine.hpp for Usine in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Thu Dec 24 07:05:53 2015 Antoine Plaskowski
// Last update Thu Dec 24 09:43:28 2015 Antoine Plaskowski
//

#ifndef		USINE_HPP_
# define	USINE_HPP_

# include	<string>
# include	<list>
# include	<vector>
# include	<random>
# include	<dirent.h>
# include	"DLL.hpp"

template<typename ptr_fct>
class	Usine
{
public:
  Usine(std::string const &path, std::string const &fct_name) :
    m_path(path),
    m_fct_name(fct_name),
    m_generator(reinterpret_cast<uintptr_t>(&path))
  {
    DIR	*dirp = opendir(path.c_str());

    if (dirp == NULL)
      throw std::exception();
    struct dirent	*entry;
    while ((entry = readdir(dirp)) != NULL)
      {
	try
	  {
	    m_dlls.push_back(new DLL(entry->d_name));
	    m_fcts.push_back(m_dlls.back()->get_symbole<ptr_fct>(m_fct_name));
	  }
	catch (...)
	  {
	  }
      }
    closedir(dirp);
  }
  template<typename T, typename ... Ts>
  T	&get(Ts ... args) const
  {
    uintmax_t	i = m_distribution(m_generator) % m_fcts.size();
    return (*m_fcts[i](args...));
  }
private:
  std::string const	m_path;
  std::string const	m_fct_name;
  std::list<DLL *>	m_dlls;
  std::vector<ptr_fct>	m_fcts;
  std::default_random_engine	m_generator;
  std::uniform_int_distribution<uintmax_t>	m_distribution;
};

#endif		/* !USINE_HPP_ */
