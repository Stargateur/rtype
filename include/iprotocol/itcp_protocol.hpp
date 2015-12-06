//
// itcp_protocol.hpp for itcp_protocol in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 03:35:29 2015 Antoine Plaskowski
// Last update Sun Dec  6 03:41:09 2015 Antoine Plaskowski
//

#ifndef		ITCP_PROTOCOL_HPP_
# define	ITCP_PROTOCOL_HPP_

# include	"ISocket.hpp"

class	ITCP_protocol
{
public:
  ITCP_protocol(ISocket const &socket);
  ~ITCP_protocol(void);
private:
  ISocket const	&m_isocket;
};

#endif		/* !ITCP_PROTOCOL_HPP_ */
