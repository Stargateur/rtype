//
// Model.hpp for Model in /home/costa_b/rendu/rtype/include/client
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Dec  9 14:35:48 2015 Kevin Costa
// Last update Wed Dec  9 15:31:46 2015 Kevin Costa
//

#ifndef		MODEL_HPP_
# define	MODEL_HPP_

# include	<vector>
# include	<map>

# include	"Button.hpp"
# include	"Sprite.hpp"

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

public:
  std::vector<AElement *> getElements(void);
  std::vector<AElement *> getActifElement(void);
  void setState(State menu);
};

#endif		/* !MODEL_HPP_ */
