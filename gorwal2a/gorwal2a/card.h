#include <iostream>

using namespace std;

#ifndef CARD_H
#define CARD_H

class card
{
private:
	int value;
	char suit; //enforce "S", "D", "C", or "H" in constructor

public:
	//constructors
	card(int v, char s);
	card();
	card(card& rhs); //copy constructor
	
	//mutators
	void setValue(int v);
	void setSuit(char s);

	//accessors
	int getValue();
	char getSuit();

	//overloaded operators
	friend ostream& operator << (ostream& os, const card& c);
	card& operator = (const card& rhs);
};

#endif //CARD_H