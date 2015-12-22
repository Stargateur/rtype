//
// Model.hpp for Model in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:35:48 2015 Kevin Costa
// Last update Tue Dec 22 15:31:41 2015 Kevin Costa
//

#ifndef		MODEL_HPP_
# define	MODEL_HPP_

# ifdef		_WIN32
#  include "ThreadWindows.hpp"
#  include "MutexWindows.hpp"
# else
#  include "ThreadUnix.hpp"
#  include "MutexUnix.hpp"
# endif

# include	<vector>
# include	<map>

# include	"Sprite.hpp"
# include "Button.hpp"

typedef enum e_state
{
	CONNEXION,
	PRINCIPAL,
	PARAMS,
	LIST,
	GAME
} State;

class Model
{
  std::map<State, std::vector<AElement *>> m_elements;
  State m_actual;

public:
  Model(void);
  ~Model(void);
  void  Game(sf::Keyboard::Key &code);
public:
  std::vector<AElement *> getElements(void);
  std::vector<AElement *> getButtonElements(void);
  void setState(State menu);
	AElement *getElementByName(const std::string &name);
};

#endif		/* !MODEL_HPP_ */
