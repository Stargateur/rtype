//
// FalseParameters.hpp for Hell in /home/rousse_3/Project/rushhell/hell/devil/bind
// 
// Made by Roussel Rodolphe
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun Nov 29 17:46:43 2015 Roussel Rodolphe
// Last update Sun Nov 29 18:03:38 2015 Roussel Rodolphe
//

#ifndef		FALSEPARAMETERS_HPP_
# define	FALSEPARAMETERS_HPP_

template<int>
struct		FalseParameter
{
};

FalseParameter<1>	_1;
FalseParameter<2>	_2;
FalseParameter<3>	_3;
FalseParameter<4>	_4;
FalseParameter<5>	_5;
FalseParameter<6>	_6;

template<typename T>
struct isFalseParameter
{
  static const int	Value = 0;
};

template<int Param>
struct isFalseParameter<FalseParameter<Param> >
{
  static const int	Value = Param;
};

#endif
