#ifndef _PRIEST_HPP_
#define _PRIEST_HPP_
#include "Unit.hpp"
#include "Board.hpp"

class Priest : public Unit {
public:
	Priest::Priest(int team, string name);

	virtual string toString();
	void target(Board *b) override;
};
#endif // _PRIEST_HPP_
