//
// Model.hpp for Model in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:35:48 2015 Kevin Costa
// Last update Sun Dec 27 21:23:49 2015 Alaric Degand
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

#include	"ITCP_protocol.hpp"
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
  std::map<State, std::vector<AElement *> *> m_elements;
  std::map<std::string, ITCP_protocol::Sprite *> m_sprites;
  sf::Font	m_font;
  bool	costabouche;
  std::string	m_swap;
  bool	m_refresh;
  bool	m_join;
  bool	m_create;
  bool	m_ready;
  
public:
  Model(void);
  ~Model(void);

public:
  std::vector<AElement *> getElements(void);
  std::vector<AElement *> getButtonElements(void);
  AElement *getElementByName(const std::string &name) const;
	AElement *getElementByUniqueID(uint64_t) const;
  AElement *getElementFocused(void);
	bool isElementInState(AElement *, const State &);
	void addElement(AElement *);
  bool	getCosta(void) const;
  Model::State getState(void) const;
  bool elementIsFocus(void);
  bool canConnect(void) const;
  bool getEnd(void) const;
  void setEnd(const bool &);
  void setState(State menu);
  void setConnect(const bool &);
  void	setCosta(bool);
  void Game(sf::Keyboard::Key &code);
  void getPressed(sf::Keyboard::Key &code);
  void updateData(void);
  bool getRefresh(void) const;
  void setRefresh(bool);
  bool getJoin(void) const;
  void setJoin(bool);
  bool getCreate(void) const;
  void setCreate(bool);
  bool getReady(void) const;
  void setReady(bool);
  void	addSprite(ITCP_protocol::Sprite *);
};

#endif		/* !MODEL_HPP_ */
