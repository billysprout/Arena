#ifndef _KNIGHT_HPP_
#define _KNIGHT_HPP_
#include "unit.hpp"
#include <string>
#include <iostream>

using namespace std;

class Knight : public Unit
{
public:
	Knight::Knight(int team, string name);
	virtual string Knight::toString() override;
};
#endif //_KNIGHT_HPP_