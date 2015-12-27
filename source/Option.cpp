//
// Option.cpp for Option in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sat Oct 24 15:42:58 2015 Antoine Plaskowski
// Last update Sun Dec 27 12:28:36 2015 Antoine Plaskowski
//

#include	<unistd.h>
#include	<string>
#include	<iostream>
#include	"Option.hpp"

Option::Option(void)
{
}

Option::~Option(void)
{  
}

std::string const	&Option::get_opt(std::string const &name) const
{
  for (auto &opt : m_opts)
    if (std::get<0>(opt) == name)
      return (std::get<2>(opt));
  throw std::invalid_argument(name + " doesn't exist");
}

std::list<std::string> const	&Option::get_pos_opt(void) const
{
  return (m_pos_opts);
}

void	Option::add_opt(std::string const &name, std::string const &description, std::string const &value)
{
  m_opts.push_back(std::make_tuple(name, description, value));
}

void	Option::sup_opt(std::string const &name)
{
  for (auto it = m_opts.begin(); it != m_opts.end();  ++it )
    if (std::get<0>(*it) == name)
      {
	m_opts.erase(it);
	return;
      }
  throw std::invalid_argument(name + "doesn't exist");
  throw std::exception();  
}

void	Option::parse_opt(int argc, char **argv)
{
  if (argc > 0)
    m_zero = argv[0];
  for (int i = 1; i < argc; i++)
    {
      std::string	arg(argv[i]);

      if (arg == "--" || arg == "-")
	return;
      else if (arg.compare(0, 2, "--") == 0)
	arg.erase(0, 2);
      else if (arg.compare(0, 1, "-") == 0)
	arg.erase(0, 1);
      else
	{
	  m_pos_opts.push_back(arg);
	  continue;
	}
      if (arg == "h" ||arg == "help")
	{
	  for (auto &opt : m_opts)
	    std::cerr << std::get<0>(opt) << " : " << std::get<1>(opt) << " = " << std::get<2>(opt);
	  throw std::logic_error("you ask for help");
	}
      for (auto &opt : m_opts)
	if (std::get<0>(opt) == arg)
	  {
	    std::get<2>(opt) = arg;
	    break;
	  }
    }
}

std::string const	&Option::get_zero(void) const
{
  return (m_zero);
}
