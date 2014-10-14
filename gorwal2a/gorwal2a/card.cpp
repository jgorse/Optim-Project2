#include <iostream>
#include "card.h"


//Empty constructor, shouldnt be called
card::card()
{
	
}

//Constructor
card::card(int v, char s)
{
	value = v;
	suit = s;
}

//copy constructor
card::card(card& rhs)
{
	suit = rhs.getSuit();
	value = rhs.getValue();
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
	if(c.value == 1)
		cout << "Ace";
	else if(c.value == 11)
		cout << "Jack";
	else if(c.value == 12)
		cout << "Queen";
	else if(c.value == 13)
		cout << "King";
	else
		cout << c.value;

	cout << " of ";

	if(c.suit == 'H')
		cout << "Hearts";
	else if(c.suit == 'D')
		cout << "Diamonds";
	else if(c.suit == 'C')
		cout << "Clubs";
	else if(c.suit == 'S')
		cout << "Spades";

	
	/*cout << "Suit: " << c.suit << ", Value: ";

	if(c.value == 1)
		cout << "Ace";
	else if(c.value == 11)
		cout << "Jack";
	else if(c.value == 12)
		cout << "Queen";
	else if(c.value == 13)
		cout << "King";
	else
		cout << c.value;
	*/
	return os;
}

//Overloaded = operator
card& card::operator=(const card& rhs)
{
	suit = rhs.suit;
	value = rhs.value;
	return *this;
}