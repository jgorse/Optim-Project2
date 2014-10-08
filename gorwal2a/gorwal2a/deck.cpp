#include <iostream>
#include "deck.h"
#include "d_node.h"
#include "card.h"

using namespace std;

//friend deck ostream& operator << (ostream& os, node <card> *front)
//friend ostream& operator << (ostream& ostr, const deck& front)
ostream& operator << (ostream& ostr, const deck& d)
{
	node <card> *currentNode = d.front;
	if (currentNode != 0)
	{
		while (currentNode->next != 0){
			cout << currentNode->nodeValue;
			currentNode = currentNode->next;
		}
		cout << currentNode->next;
	}
	return ostr;
}

deck::deck()
{
	char suit;
	int count = 0;
	for (int i = 0; i <= 3; i++){
		for (int j = 13; j >= 0; j--){
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
			if (j == 13 && suit == 'C'){
				newCard->next = 0;
				front = newCard;
			}
			front->next = newCard;
			front = newCard;
		}
	}
}