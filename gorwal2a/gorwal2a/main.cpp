#include <iostream>
#include <vector>
#include "card.h"
#include "deck.h"


int playflip(deck* playerDeck)
{
	int score = 0;
	int Choice = -1;
	
	cout << "The original deck is: \n" << *playerDeck << "\n";//Debug print
	cout << "\n\nNow we shuffle the deck...\n\n";

	for(int i=0; i<3; i++)
	{
		playerDeck->shuffle();
	}

	//Debug print
	cout << "The shuffled deck is: \n"<< *playerDeck << "\n\n\n";

	cout << "Now we draw a hand for the player.\n";
	vector <card> hand;
	for(int i = 0; i<24; i++)
	{
		hand.push_back(playerDeck->deal());
	}

	//Debug print
	cout << "\n\nThe rest of the deck is:\n" << *playerDeck << "\n\n";

	//Debug print
	cout << "The player's hand is: \n";
	for(int i = 0; i<24; i++)
	{
		cout << i+1 << ": " << hand[i] << "\n";
	}

	

	while(true)
	{
		card currentCard;
		cout << "\nEnter a card to flip over, or enter 0 to end the game\n";
		cout << "Current score: " <<score << "\n";
		cout << "Choice: ";
		cin >> Choice;

		if(Choice == 0)
			break;
		else if(Choice > 24 || Choice < 0)
			continue;
		else if(Choice > 0)
		{
			currentCard = hand[Choice-1];

			cout << "Chosen card: "<<currentCard<<"\n";

			if(currentCard.getValue() == 1 )
			{
				score += 10;
				cout << "Gain 10 points!\n";
			}
			else if(currentCard.getValue()  >= 11 && currentCard.getValue() <= 13 )
			{	
				score += 5;
				cout << "Gain 5 points!\n";
			}
			else if(currentCard.getValue()  >= 8 && currentCard.getValue() <= 10 )
			{	
				cout << "No point change!\n";
			}
			else if(currentCard.getValue()  == 7 )
			{
				score /= 2;
				cout << "Lose half your points!\n";
			}
			else if(currentCard.getValue()  >= 2 && currentCard.getValue() <= 6 )
			{
				score = 0;
				cout << "Lose all your points!\n";
			}
			if(currentCard.getSuit() == 'H')
			{
				score++;
				cout << "Extra point for a Heart!\n";
			}

		}
	}


	return score;
}

int main()
{
	deck test;
	int score = playflip(&test);
	
	cout << "\n\nSCORE: " << score << "\n";

	system("pause");

	return 0;
}