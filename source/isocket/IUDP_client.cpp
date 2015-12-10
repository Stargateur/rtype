//
// IUDP_client.cpp for IUDP_client in /home/plasko_a/projet/cplusplus/rtype
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Fri Nov 20 12:09:40 2015 Antoine Plaskowski
// Last update Thu Dec 10 02:27:28 2015 Antoine Plaskowski
//

#include	"IUDP_client.hpp"

IUDP_client::~IUDP_client(void)
{
}

IUDP_client_exception::IUDP_client_exception(void) noexcept
{
}

IUDP_client_exception::IUDP_client_exception(IUDP_client_exception const &) noexcept
{
}

IUDP_client_exception::~IUDP_client_exception(void) noexcept
{
}

IUDP_client_exception	&IUDP_client_exception::operator=(IUDP_client_exception const &) noexcept
{
  return (*this);
}
