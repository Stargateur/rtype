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

class Network
{
	Model &m_model;
	ISelect &m_select;
	AThread *m_thread;
	AMutex *m_mutex;
	ITCP_client *m_tcpClient;
	IUDP_client *m_udpClient;
	Client *m_client;
	TCP_protocol *m_tcpProto;
	Player *m_player;
	UDP_protocol *m_udpProto;
	bool m_end;

public:
	Network(Model &);
	~Network();

public:
	AThread *getThread(void) const;
	void setThread(AThread *);
	void setMutex(AMutex *);
	void tryConnect(void);
	void update(void);
	void loop(void);
};

#endif