#include <iostream>
#include "d_node.h"

using namespace std;

class deck
{

public: 
	deck();

private:
	node <card> *front;
	friend ostream& operator << (ostream& ostr, const deck& d);

};