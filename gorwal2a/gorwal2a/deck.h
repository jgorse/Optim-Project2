#include <iostream>
#include "d_node.h"
#include "card.h"

using namespace std;


class deck
{

public: 
	//constructor
	deck();

	//destructor
	deck::~deck();

	//friend overloaded operator
	friend ostream& operator << (ostream& ostr, const deck& d);

	card deck::deal();

	void deck::replace(deck& d, node <card>* newCard);

	node <card>* deck::shuffle();

private:
	//top card of the deck
	node <card> *front;
	
};