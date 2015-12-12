//
// ThreadPool.hpp for rtype in /home/rousse_3/Project/rtype/source/server/threadPool
// 
// Made by Roussel Rodolphe
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Dec 12 16:57:23 2015 Roussel Rodolphe
// Last update Sat Dec 12 18:42:48 2015 Roussel Rodolphe
//

#ifndef		THREADPOOL_HPP_
# define	THREADPOOL_HPP_

# include	<thread>
# include	<vector>
# include	"Task.hpp"

class				ThreadPool
{
private:
  int				_nbThread;
  std::vector<std::thread>	_threads;
  std::vector<Task*>		_tasks;
public:
  ThreadPool(int nbThread = 10);
  ~ThreadPool(void);

  int				start(Function<int(int)> f);
  bool				hasReturn(int id);
  int				getReturn(int id);
};

#endif
