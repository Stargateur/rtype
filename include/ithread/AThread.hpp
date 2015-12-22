#ifndef		ATHREAD_HPP_
# define	ATHREAD_HPP_

# include <cstdlib>

class AThread
{
protected:
	void *thread;

public:
	AThread();
	~AThread();

public:
	virtual bool create(void *(*ptr)(void *), void *) = 0;
	virtual void wait(void) = 0;
	virtual void exit(unsigned int code = 0) = 0;
	virtual void terminate(void) = 0;
};

#endif