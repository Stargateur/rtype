#include "MutexWindows.hpp"

Mutex::Mutex()
{
	this->mutex = new LPCRITICAL_SECTION;
	InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(this->mutex));
}


Mutex::~Mutex()
{
	DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(this->mutex));
	delete (this->mutex);
}

void Mutex::lock(void)
{
	EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(this->mutex));
}

bool Mutex::trylock(void)
{
	return (TryEnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(this->mutex)));
}

void Mutex::unlock(void)
{
	LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(this->mutex));
}
