//
// TCP_packet_recv.hpp for TCP_packet_recv in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 04:00:47 2015 Antoine Plaskowski
// Last update Tue Dec  8 18:15:08 2015 Antoine Plaskowski
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
  ~TCP_packet_recv(void);
  template<typename T>
  void	get_int(T &value)
  {
    value = 0;
    for (uintmax_t i = 0; i < sizeof(T); i++)
      value |= (m_packet.data[m_packet.size++] << (i * std::numeric_limits<uint8_t>::digits));
  }
  void	get_string(std::string &string);
  bool	recv(ITCP_client const &socket);
  void	reset(void);
private:
  uintmax_t	m_recv;
};

#endif		/* !TCP_PACKET_RECV_HPP_ */
