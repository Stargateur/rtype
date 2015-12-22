#include "MutexUnix.hpp"

Mutex::Mutex()
{
	pthread_mutex_init(reinterpret_cast<pthread_mutex_t *>(this->mutex), NULL);
}

Mutex::~Mutex()
{
	pthread_mutex_destroy(reinterpret_cast<pthread_mutex_t *>(this->mutex));
}

void Mutex::lock(void)
{
	pthread_mutex_lock(reinterpret_cast<pthread_mutex_t *>(this->mutex));
}

bool Mutex::trylock(void)
{
	return (pthread_mutex_trylock(reinterpret_cast<pthread_mutex_t *>(this->mutex)) == 0);
}

void Mutex::unlock(void)
{
	pthread_mutex_unlock(reinterpret_cast<pthread_mutex_t *>(this->mutex));
}
