//
// ThreadPool.cpp for rtype in /home/rousse_3/Project/rtype/source/server/threadPool
// 
// Made by Roussel Rodolphe
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Dec 12 17:26:46 2015 Roussel Rodolphe
// Last update Sat Dec 12 19:15:13 2015 Roussel Rodolphe
//

#ifdef		_WIN32
# include <io.h>
# include <Windows.h>
#else
# include	<unistd.h>
#endif
#include	"ThreadPool.hpp"

static void	waitingTask(Task &t)
{
  while (t.getEnd() != true)
    {
			if (t.haveTask() == true)
			{
				int		ret = t.getTask()(t.getId());
				t.setReturn(ret);
			}
			else
#ifdef	_WIN32
				Sleep(100);
#else
	usleep(100);
#endif
    }
}

ThreadPool::ThreadPool(int nbThread) :
  _nbThread(nbThread),
  _threads()
{
  for (int i = 0; i < _nbThread; i++)
    {
      _tasks.push_back(new Task());
      _threads.push_back(std::thread(waitingTask, std::ref(*_tasks[i])));
    }
}

ThreadPool::~ThreadPool(void)
{
  int		size = _tasks.size();
  
  for (int i = 0; i < size; i++)
    _tasks[i]->setEnd();
  for (int i = 0; i < size; i++)
    _threads[i].join();
}

int		ThreadPool::start(Function<int(int) >f)
{
  int		size = _tasks.size();
  
  for (int i = 0; i < size; i++)
    if (_tasks[i]->isFree())
      {
	_tasks[i]->setTask(f);
	return (_tasks[i]->getId());
      }
  _tasks.push_back(new Task());
  _threads.push_back(std::thread(waitingTask, std::ref(*_tasks[size])));
  _tasks[size]->setTask(f);
  return (_tasks[size]->getId());
}

bool		ThreadPool::hasReturn(int id)
{
  int		size = _tasks.size();
  
  for (int i = 0; i < size; i++)
    if (_tasks[i]->getId() == id)
      return (_tasks[i]->hasReturn());
  return (false);
}

int		ThreadPool::getReturn(int id)
{
  int		size = _tasks.size();
  
  for (int i = 0; i < size; i++)
    if (_tasks[i]->getId() == id)
      return (_tasks[i]->getReturn());
  return (0);
}
