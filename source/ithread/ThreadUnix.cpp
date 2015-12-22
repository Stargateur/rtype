#include "ThreadUnix.hpp"

Thread::Thread()
{
}


Thread::~Thread()
{
}

bool Thread::create(void *(*ptr)(void *), void *data)
{
  pthread_create(reinterpret_cast<pthread_t *>(this->thread), NULL, ptr, data);
  return (this->thread != NULL);
}

void Thread::wait(void)
{
	pthread_join(*reinterpret_cast<pthread_t *>(this->thread), NULL);
}

void Thread::end(unsigned int code)
{
	pthread_exit(&code);
}

void Thread::terminate(void)
{
	pthread_cancel(*reinterpret_cast<pthread_t *>(this->thread));
}
