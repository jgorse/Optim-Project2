#include <iostream>
#include "card.h"


//Empty constructor, shouldnt be called
card::card()
{
	cout<<"This shouldn't be called!\n";
}

//Constructor
card::card(int v, char s)
{
	value = v;
	suit = s;
}

//mutator for 'value'
void card::setValue(int v)
{
	value = v;
}

//'mutator for suit'
void card::setSuit(char s)
{
	suit = s;
}

//accessor for 'value'
int card::getValue()
{
	return value;
}

//accessor for 'suit'
char card::getSuit()
{
	return suit;
}

//Overloaded << operator to print 'card' object
ostream& operator << (ostream& os, const card& c)
{
	cout << "\nSuit: " << c.suit << "\nValue: " << c.value << "\n";
}