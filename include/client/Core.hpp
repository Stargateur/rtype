//
// Core.hpp for Core in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:43:00 2015 Kevin Costa
// Last update Wed Dec  9 16:57:19 2015 Kevin Costa
//

#ifndef		CORE_HPP_
# define	CORE_HPP_

# include	"ICore.hpp"
# include	"RView.hpp"

class Core : public ICore
{
 private:
	std::vector<RView *>	_lstView;
	RView*				_currentView;
	sf::VideoMode video;
	sf::Event event;

public:
  Core(void);
  ~Core(void);

public:
  bool init(void);
  void loop(void);
  void checkEvents(RView *);
  void addView(RView *);
  void drawView();
};

#endif		/* !CORE_HPP_ */
