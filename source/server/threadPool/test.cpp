#include	<unistd.h>
#include	<iostream>
#include	"bind/bind.hpp"
#include	"ThreadPool.hpp"

int		print(int arg, std::string str)
{
  std::cout << str << arg << std::endl;
  usleep(100000);
  std::cout << str << arg << std::endl;
  return (41);
}

int		main(void)
{
  std::vector<int>	ids;
  ThreadPool		pool(5);

  for (int i = 0; i < 10; i++)
    ids.push_back(pool.start(bind(print, _1, "Ceci est un test : ")));
  return (0);
}
