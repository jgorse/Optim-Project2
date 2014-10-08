#include <iostream>
#include "d_node.h"
#include "card.h"

using namespace std;


class deck
{

public: 
	//constructor
	deck();

private:
	//top card of the deck
	node <card> *front;

	//friend overloaded operator
	friend ostream& operator << (ostream& ostr, const deck& d);

};