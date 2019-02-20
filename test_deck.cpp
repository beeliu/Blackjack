#include <iostream>
#include "deck.h"

using namespace std;


int main()
{
	try {
		// make a deck
		Deck deck(52);
		cout << deck.return_deck() << endl;

		deck.shuffle();
		cout << deck.return_deck() << endl;
		cout << deck.number_cards() << endl;

		// deal cards
		Card card1 = deck.deal_card();
		Card card2 = deck.deal_card();
		Card card3 = deck.deal_card();

		cout << deck.number_cards() << endl;
		cout << card1.return_card() << endl;
		cout << card2.return_card() << endl;
		cout << card3.return_card() << endl;

		//deal remaining cards
		Card *cards = new Card[deck.number_cards()];
		int number = deck.number_cards();
		for (int i = 0; i < number; i ++)
		{
			cards[i] = deck.deal_card();
			cout << deck.number_cards()<< endl;
		}

		Card card4 = deck.deal_card();
		
		delete[] cards;
		
	}
	catch (char const* e)
	{
		cout << "no more cards in deck" << endl;
	}
}
