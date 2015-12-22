#ifndef		MUTEXUNIX_HPP_
# define	MUTEXUNIX_HPP_

# include <pthread.h>

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
