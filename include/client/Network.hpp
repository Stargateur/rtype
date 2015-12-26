#ifndef		NETWORK_HPP_
# define	NETWORK_HPP_

# include "TCP_protocol.hpp"
# include "TCP_client.hpp"
# include "Model.hpp"

class Network
{
	Model &m_model;
	AThread *m_thread;
	AMutex *m_mutex;
	ITCP_client *m_client;
	bool m_end;

public:
	Network(Model &);
	~Network();

public:
	AThread *getThread(void) const;
	void setThread(AThread *);
	void setMutex(AMutex *);
	void loop(void);
};

#endif