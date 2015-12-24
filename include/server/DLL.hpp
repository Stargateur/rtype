//
// DLL.hpp for DLL in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:26:06 2015 Antoine Plaskowski
// Last update Wed Dec 23 18:51:02 2015 Antoine Plaskowski
//

#ifndef		DLL_HPP_
# define	DLL_HPP_

# include	<iostream>
# include	<string>
# include	<dlfcn.h>

class		DLL
{
public:
  DLL(std::string const &name);
  ~DLL(void);
  template<typename ptr_fct, typename ref_fct>
  ref_fct	get_symbole(std::string const &name) const
  {
    (void)dlerror();
    void	*symbole = dlsym(m_handle, name.c_str());
    char const *str = dlerror();
    if (str != NULL)
      {
	std::cerr << str << std::endl;
	throw std::exception();
      }
    return (*reinterpret_cast<ptr_fct>(symbole));
  }
  std::string const	&get_name(void) const;
private:
  void	*m_handle;
  std::string const	m_name;
};

#endif		/* !DLL_HPP_ */
