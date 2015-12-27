#ifndef		NETWORK_HPP_
# define	NETWORK_HPP_

# include "Client.hpp"
# include "Player.hpp"
# include "TCP_protocol.hpp"
# include "UDP_protocol.hpp"
# include "TCP_client.hpp"
# include "UDP_client.hpp"
# include "Model.hpp"
# include "Select.hpp"
# ifdef		_WIN32
#  include "Time_Windows.hpp"
# else
#  include "Time.hpp"
# endif

class Network
{
	Model &m_model;
	ISelect &m_select;
	ITime *m_time;
	AThread *m_thread;
	AMutex *m_mutex;
	ITCP_client *m_tcpClient;
	IUDP_client *m_udpClient;
	Client *m_client;
	TCP_protocol *m_tcpProto;
	Player *m_player;
	UDP_protocol *m_udpProto;
	bool m_end;
  std::string m_login;
	std::string m_ip;

public:
	Network(Model &);
	~Network();

public:
	AThread *getThread(void) const;
	const std::string &getIP(void) const;
	void setThread(AThread *);
	void setMutex(AMutex *);
	void tryConnectTCP(void);
	void tryConnectUDP(const std::string &port);
	void update(void);
	void loop(void);
};

#endif
