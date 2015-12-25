#include "Network.hpp"

Network::Network(Model &model) :
	m_model(model), m_end(false), m_thread(NULL), m_mutex(NULL)
{
}


Network::~Network()
{
}

AThread * Network::getThread(void) const
{
	return (this->m_thread);
}

void Network::setThread(AThread *th)
{
	this->m_thread = th;
}

void Network::setMutex(AMutex *mutex)
{
	this->m_mutex = mutex;
}

void Network::loop(void)
{
	while (!this->m_end)
	{
		this->m_mutex->lock();
		this->m_end = this->m_model.getEnd();
		this->m_mutex->unlock();
	}
}
