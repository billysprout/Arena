#ifndef _MARKSMAN_HPP_
#define _MARKSMAN_HPP_
#include <string>
#include "unit.hpp"
class Marksman : public Unit {
public:
	Marksman::Marksman(int team, string name);

	virtual string toString();
};
#endif // _MARKSMAN_HPP_