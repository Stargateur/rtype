//
// Option.hpp for Option in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Oct 24 15:43:06 2015 Antoine Plaskowski
// Last update Thu Dec 24 07:24:27 2015 Antoine Plaskowski
//

#ifndef		OPTION_HPP_
# define	OPTION_HPP_

# include	<string>
# include	<tuple>
# include	<list>

class	Option
{
public:
  Option(void);
  ~Option(void);
  std::string const	&get_opt(std::string const &name) const;
  std::list<std::string> const	&get_pos_opt(void) const;
  void	add_opt(std::string const &name, std::string const &description = "", std::string const &value = "");
  void	sup_opt(std::string const &name);
  void	parse_opt(int argc, char **argv);
  std::string const	&get_zero(void) const;
private:
  using m_opt = std::tuple<std::string, std::string, std::string>;
  std::list<m_opt>	m_opts;
  std::list<std::string>	m_pos_opts;
  std::string	m_zero;
};

#endif		/* !OPTION_HPP_ */
