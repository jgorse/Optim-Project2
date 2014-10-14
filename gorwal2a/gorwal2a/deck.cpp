#include <iostream>
#include "deck.h"
#include "d_node.h"
#include "card.h"

using namespace std;

//overloaded << operator, prints values of all cards in the deck.
ostream& operator<< (ostream& ostr, const deck& d)
{
	node <card> *currentNode = d.front;
	if (currentNode != 0 && currentNode->next != NULL)
	{
		while (currentNode->next != 0){
			cout << currentNode->nodeValue << endl;
			currentNode = currentNode->next;
		}
		cout << currentNode->nodeValue; //print the last card
	}
	else 
	{
		cout << "Deck does not exist.\n";
	}
	return ostr;
}

deck::deck()
{
	char suit;
	int count = 0;
	//make the deck in reverse (put down S13 first and stack cards on top)
	for (int i = 3; i >= 0; i--){
		for (int j = 13; j > 0; j--){
			switch (i)
			{
				case 0:
					suit = 'C';
					break;
				case 1:
					suit = 'D';
					break;
				case 2:
					suit = 'H';
					break;
				case 3:
					suit = 'S';
					break;
			}
			node <card> *newCard = new node<card>;
			newCard->nodeValue.setValue(j);
			newCard->nodeValue.setSuit(suit);
			//set the last card's next value to 0
			if (j == 13 && suit == 'S'){
				front = newCard;
				newCard->next = 0;
			}
			//connect card to the one below it, set the newest card as the top of the deck
			else{ 
				newCard->next = front;
				front = newCard;
			}
		}
	}
}

deck::~deck()
{
	node <card> *currentNode = front;
	node <card> *nextNode = front;
	if (currentNode != 0)
	{
		while (currentNode->next != 0){
			nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
		delete currentNode; //print the last card
		front = NULL;
	}
}

card deck::deal()
{
	node <card>* removedCard = front;
	front = removedCard->next;
	return removedCard->nodeValue;
}

void deck::replace(deck& d, node <card>* newCard)
{
	node <card> *currentNode = d.front;
	if (currentNode != 0 && currentNode->next != NULL)
	{
		//go to end of deck
		while (currentNode->next != 0){
			currentNode = currentNode->next;
		}
		//connect last card to new card
		currentNode->next = newCard;
	}
	else 
	{
		cout << "Deck does not exist.\n";
	}
}