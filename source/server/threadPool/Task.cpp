//
// Task.cpp for rtype in /home/rousse_3/Project/rtype/source/server/threadPool
// 
// Made by Roussel Rodolphe
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Dec 12 17:56:05 2015 Roussel Rodolphe
// Last update Sat Dec 12 18:56:22 2015 Roussel Rodolphe
//

#include	"ThreadPool.hpp"

int		Task::id = 0;

static int	doNothing(int arg)
{
(void)arg;
return (0);
}

Task::Task() :
  _id(Task::id),
  _mutEnd(),
  _end(false),
  _mutTask(),
  _hasTask(false),
  _task(doNothing),
  _mutRet(),
  _return(0),
  _isFinished(false)
{
  Task::id++;
}

Task::~Task(void)
{}

bool		Task::getEnd(void)
{
  bool		end;
  
  _mutEnd.lock();
  end = _end;
  _mutEnd.unlock();
  return (end);
}

void		Task::setEnd(void)
{
  _mutEnd.lock();
  _end = true;
  _mutEnd.unlock();
}

bool		Task::isFree(void)
{
  bool		isFree;
  
  _mutTask.lock();
  _mutRet.lock();
  isFree = _hasTask == false && _isFinished == false;
  _mutTask.unlock();
  _mutRet.unlock();
  return (isFree);
}

bool		Task::haveTask(void)
{
  bool		task;
  
  _mutTask.lock();
  task = _hasTask;
  _mutTask.unlock();
  return (task);
}

Function<int(int)>	Task::getTask(void)
{
  Function<int(int)>	f(doNothing);
  
  _mutTask.lock();
  f = _task;
  _mutTask.unlock();
  return (f);
}

void		Task::setTask(Function<int(int)> f)
{
  _mutTask.lock();
  _task = f;
  _hasTask = true;
  _mutTask.unlock();
}

void		Task::setReturn(int ret)
{
  _mutRet.lock();
  _mutTask.lock();
  _hasTask = false;
  _isFinished = true;
  _return = ret;
  _mutTask.unlock();
  _mutRet.unlock();
}

bool		Task::hasReturn(void)
{
  bool		ret;
  
  _mutRet.lock();
  ret = _isFinished;
  _mutRet.unlock();
  return (ret);
}

int		Task::getReturn(void)
{
  int		ret;

  _mutRet.lock();
  ret = _return;
  _isFinished = false;
  _mutRet.unlock();
  return (ret);
}

int		Task::getId(void)
{
  return (_id);
}
