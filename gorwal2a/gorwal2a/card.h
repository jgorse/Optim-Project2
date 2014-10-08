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
	
	//mutators
	void setValue(int v);
	void setSuit(char s);

	//accessors
	int getValue();
	char getSuit();

	//friend overloaded operator
	friend ostream& operator << (ostream& os, const card& c);

};

#endif //CARD_H