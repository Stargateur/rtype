#ifndef		MUTEXWINDOWS_HPP_
# define	MUTEXWINDOWS_HPP_

# include <Windows.h>

# include "AMutex.hpp"

class Mutex : public AMutex
{
public:
	Mutex();
	~Mutex();

public:
	void lock(void);
	bool trylock(void);
	void unlock(void);
};

#endif
