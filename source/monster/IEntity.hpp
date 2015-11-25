//
// IEntity.hpp for  in /home/degand/Projects/3eme_annee/CPP_A/rtype/source/monster
// 
// Made by Alaric
// Login   <degand@epitech.net>
// 
// Started on  Wed Nov 25 15:19:46 2015 Alaric
// Last update Wed Nov 25 15:26:47 2015 Alaric
//

#ifndef		IENTITY_HPP_
# define	IENTITY_HPP_

class		IEntity
{
private :
  size_t	_Hp;
  size_t	_sizeY;
  size_t	_sizeX;
  size_t	_velocity;

  virtual size_t patern(const size_t x) = 0;
  //fonction d'action

};

#endif		/* IENTITY_HPP_ */
