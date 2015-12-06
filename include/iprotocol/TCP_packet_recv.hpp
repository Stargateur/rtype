//
// TCP_packet_recv.hpp for TCP_packet_recv in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 04:00:47 2015 Antoine Plaskowski
// Last update Sun Dec  6 04:12:53 2015 Antoine Plaskowski
//

#ifndef		TCP_PACKET_RECV_HPP_
# define	TCP_PACKET_RECV_HPP_

# include	<limits>
# include	<cstring>
# include	"ATCP_packet.hpp"

class	TCP_packet_recv : public ATCP_packet
{
public:
  TCP_packet_recv(void);
  template<typename T>
  bool	get_int(T &value)
  {
    value = 0;
    for (uintmax_t i = 0; i < sizeof(T); i++)
      {
	value |= (m_packet.data[m_recv_data] << (i * std::numeric_limits<uint8_t>::digits));
	if (m_recv_data++ == UINT16_MAX)
	  return (true);
      }
    return (false);
  }
  bool	get_string(std::string &string);
  bool	recv(ITCP_client const &socket);
  bool	is_recv(void) const;
  void	reset(void);
private:
  uintmax_t	m_recv;
  uint16_t	m_recv_data;
  bool	m_is_recv;
};

#endif		/* !TCP_PACKET_RECV_HPP_ */
