//
// Model.hpp for Model in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:35:48 2015 Kevin Costa
// Last update Fri Dec 25 18:36:58 2015 Alaric Degand
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


class Model
{
public:
  typedef enum e_state
    {
      CONNEXION,
      PRINCIPAL,
      PARAMS,
      LIST,
      GAME
    } State;

private:
  std::map<State, std::vector<AElement *>> m_elements;
  State m_actual;
  bool m_endExec;

public:
  Model(void);
  ~Model(void);

public:
  std::vector<AElement *> getElements(void);
  std::vector<AElement *> getButtonElements(void);
  void setEnd(const bool &);
  void setState(State menu);
  bool getEnd(void) const;
  Model::State getState(void) const;
  AElement *getElementByName(const std::string &name);
  void Game(sf::Keyboard::Key &code); // Change le nom
  void updateData(void);
};

#endif		/* !MODEL_HPP_ */
