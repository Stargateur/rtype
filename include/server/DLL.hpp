//
// DLL.hpp for DLL in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:26:06 2015 Antoine Plaskowski
// Last update Thu Dec 24 11:03:03 2015 Antoine Plaskowski
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
  template<typename ptr_fct>
  ptr_fct	get_symbole(std::string const &name) const
  {
    std::cout << "lol" << std::endl;
    (void)dlerror();
    void	*symbole = dlsym(m_handle, name.c_str());
    char const *str = dlerror();
    if (str != NULL)
      throw std::logic_error(str);
    return (reinterpret_cast<ptr_fct>(symbole));
  }
  std::string const	&get_name(void) const;
private:
  void	*m_handle;
  std::string const	m_name;
};

#endif		/* !DLL_HPP_ */
