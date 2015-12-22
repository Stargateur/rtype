#ifndef		THREADUNIX_HPP_
# define	THREADUNIX_HPP_

# include	<pthread.h>

# include "AThread.hpp"

class Thread : public AThread
{
public:
	Thread();
	~Thread();

public:
	bool create(void *(*ptr)(void *), void *);
	void wait(void);
	void end(unsigned int code = 0);
	void terminate(void);
};

#endif