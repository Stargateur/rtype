#include "ThreadWindows.hpp"

Thread::Thread()
{
	this->thread = new HANDLE;
}


Thread::~Thread()
{
	delete (reinterpret_cast<HANDLE>(this->thread));
}

bool Thread::create(void *(*ptr)(void *), void *data)
{
	this->thread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(ptr), data, 0, NULL);
	return (this->thread != NULL);
}

void Thread::wait(void)
{
	WaitForSingleObject(this->thread, INFINITE);
}

void Thread::exit(unsigned int code)
{
	ExitThread(code);
}

void Thread::terminate(void)
{
	TerminateThread(this->thread, NULL);
}
