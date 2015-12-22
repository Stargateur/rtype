#ifndef		AMUTEX_HPP_
# define	AMUTEX_HPP_

# include <cstdlib>

class AMutex
{
protected:
	void *mutex;

public:
	AMutex();
	~AMutex();

public:
	virtual void lock(void) = 0;
	virtual bool trylock(void) = 0;
	virtual void unlock(void) = 0;
};

#endif
