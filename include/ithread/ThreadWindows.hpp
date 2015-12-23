#ifndef		THREADWINDOWS_HPP_
# define	THREADWINDOWS_HPP_

# include	<Windows.h>

# include "AThread.hpp"

class Thread : public AThread
{
public:
	Thread();
	~Thread();

public:
	bool create(void *(*ptr)(void*), void *);
	void wait(void);
	void exit(unsigned int code = 0);
	void terminate(void);
};

#endif
