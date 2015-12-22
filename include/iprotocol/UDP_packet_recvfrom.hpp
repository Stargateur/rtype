//
// UDP_packet_recvfrom.hpp for UDP_packet_recvfrom in /home/plasko_a/projet/cplusplus/rtype/include/iprotocol
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Dec  6 04:00:47 2015 Antoine Plaskowski
// Last update Tue Dec 22 16:49:55 2015 Antoine Plaskowski
//

#ifndef		UDP_PACKET_RECVFROM_HPP_
# define	UDP_PACKET_RECVFROM_HPP_

# include	<limits>
# include	<cstring>
# include	"AUDP_packet.hpp"

class	UDP_packet_recvfrom : public AUDP_packet
{
public:
  UDP_packet_recvfrom(void);
  ~UDP_packet_recvfrom(void);
  template<typename T>
  void	get(T &value)
  {
    uint8_t	*data(reinterpret_cast<uint8_t *>(&value));

    for (uintmax_t i = 0; i < sizeof(T); i++)
      data[i] = m_packet.data[m_packet.size++];
  }
  void	get(std::string &string);
  bool	recvfrom(IUDP_client const &socket, u_sockaddr &sockaddr, socklen_t &len);
private:
  uintmax_t	m_recvfrom;
};

#endif		/* !UDP_PACKET_RECVFROM_HPP_ */
