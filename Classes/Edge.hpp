#ifndef _EDGE_HPP_
#define _EDGE_HPP_
#include "Unit.hpp"
//the non-traversible units at the edge of the baord.

class Edge : public Unit
{
public:
	Edge::Edge();
	virtual string toString();
};

#endif //_EDGE_HPP_