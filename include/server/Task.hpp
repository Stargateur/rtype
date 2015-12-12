//
// Task.hpp for rtype in /home/rousse_3/Project/rtype/source/server/threadPool
// 
// Made by Roussel Rodolphe
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Dec 12 18:41:51 2015 Roussel Rodolphe
// Last update Sat Dec 12 18:52:24 2015 Roussel Rodolphe
//

#ifndef		TASK_HPP_
# define	TASK_HPP_

# include	<mutex>
# include	"Function.hpp"

class			Task
{
private:
  int			_id;
  std::mutex		_mutEnd;
  bool			_end;
  std::mutex		_mutTask;
  bool			_hasTask;
  Function<int(int)>	_task;
  std::mutex		_mutRet;
  int			_return;
  bool			_isFinished;
  static int		id;
public:
  Task();
  ~Task(void);

  bool			getEnd(void);
  void			setEnd(void);
  bool			isFree(void);
  bool			haveTask(void);
  Function<int(int)>	getTask(void);
  void			setTask(Function<int(int)> f);
  void			setReturn(int ret);
  bool			hasReturn(void);
  int			getReturn(void);
  int			getId(void);
};

#endif
