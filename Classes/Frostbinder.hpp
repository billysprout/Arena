#ifndef _FROSTBINDER_HPP_
#define _FROSTBINDER_HPP_
#include "unit.hpp"
#include <string>
#include <iostream>

using namespace std;

class Frostbinder : public Unit
{
public:
	Frostbinder::Frostbinder(int team, string name);
	virtual string Frostbinder::toString() override;
	virtual void attack(Unit* unit) override;
};
#endif //_FROSTBINDER_HPP_