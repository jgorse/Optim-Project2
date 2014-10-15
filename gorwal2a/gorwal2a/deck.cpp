#include <iostream>
#include "deck.h"
#include "d_node.h"
#include "card.h"
#include <random>
#include <ctime>

using namespace std;


//overloaded << operator, prints values of all cards in the deck.
ostream& operator<< (ostream& ostr, const deck& d)
{
	node <card> *currentNode = d.front;
	if (currentNode != 0 && currentNode->next != NULL)
	{
		while (currentNode->next != NULL){
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
			//set the last card's next value to NULL
			if (j == 13 && suit == 'S'){
				front = newCard;
				newCard->next = NULL;
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

node <card>* deck::shuffle()
{
	//create newhead pointer
	node <card> *newhead;
	//create newcurrent, oldcurrent pointer pointer
	node <card> * newcurrent;
	node <card> * oldcurrent;
	node <card> * previous;
	
	//get random number between 1 and 52
	std::srand(time(0));
	int randomnum = rand() % 52;
	oldcurrent = front;
	for(int i=0; i<randomnum; i++)
	{
		previous = oldcurrent;
		oldcurrent = oldcurrent->next;
	}
	//This sets the new head to a random element in the old list
	newhead = oldcurrent;
        //delete oldcurrent from the old list to avoid dulicates
	previous->next = oldcurrent->next;
	
	//set the current pointers to heads of both lists
	oldcurrent = front;
	newcurrent = newhead;
	for(int i=51; i>0; i--)
	{
		//get random number
		std::srand(time(0));
		randomnum = rand() % 52;
		for(int j=randomnum; j<i; j++)
		{
			if (oldcurrent->next != NULL){
			//move to random'th item in old list
				previous = oldcurrent;
				oldcurrent = oldcurrent->next;
			}
		}
		
		//make new list's next item the random'th item in old list.
		newcurrent->next = oldcurrent;
		
		//move to the next item in the newlist
		newcurrent = newcurrent->next;
		
		//delete oldcurrent from old list to avoid duplicates
		previous->next = oldcurrent->next;
	}

	return newhead;
}