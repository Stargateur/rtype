//
// Model.hpp for Model in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:35:48 2015 Kevin Costa
// Last update Sun Dec 27 13:25:43 2015 Alaric Degand
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
      CONNEXION = 0,
      PRINCIPAL = 1,
      PARAMS = 2,
      LIST = 3,
      GAME = 4
    } State;

private:
  State m_actual;
  bool m_canConnect;
  bool m_endExec;
  std::map<State, std::vector<AElement *>> m_elements;
  bool connexionbox;
  sf::Font	m_font;
  bool	costabouche;
  std::string	m_swap;
  
public:
  Model(void);
  ~Model(void);

public:
  std::vector<AElement *> getElements(void);
  std::vector<AElement *> getButtonElements(void);
	AElement *getElementByName(const std::string &name) const;
	AElement *getElementFocused(void);
	bool	getCosta(void) const;
	Model::State getState(void) const;
	bool elementIsFocus(void);
	bool canConnect(void) const;
	bool getEnd(void) const;
	void setEnd(const bool &);
  void setState(State menu);
	void setConnect(const bool &);
  void	setCosta(bool);
  void Game(sf::Keyboard::Key &code); // Change le nom
  void getPressed(sf::Keyboard::Key &code);
  void updateData(void);
};

#endif		/* !MODEL_HPP_ */
