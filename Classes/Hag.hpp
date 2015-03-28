#ifndef _HAG_HPP_
#define _HAG_HPP_
#include "Unit.hpp"
#include "Board.hpp"
#include <string>

class Hag : public Unit {
public:
	Hag::Hag(int team, string name);
	virtual string toString();
	void target(Board *b) override;
};
#endif