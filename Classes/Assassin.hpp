#ifndef _ASSASSIN_HPP_
#define _ASSASSIN_HPP_
#include "Unit.hpp"
#include "Board.hpp"
class Assassin : public Unit {
public:
	Assassin::Assassin(int team, string name);

	virtual string toString();
	void target(Board *b) override;
};
#endif