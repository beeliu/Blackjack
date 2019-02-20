/* This is the Deck class for Poker Game */

#include "deck.h"

	//Constructor
	Deck:: Deck(int number_cards)
	{
		cards = number_cards;
		total = number_cards;
		deck = new Card[number_cards];
		//assigns suits and ranks
		for (int i = 0; i < number_cards; i ++)
		{
			Card temp(0, "Hearts");
			if (i%4 == 0)
			{
				temp.assign_rank(i%13);
				temp.assign_suit("Hearts");
			}
			else if (i%4 == 1)
			{
				temp.assign_rank(i%13);
				temp.assign_suit("Diamonds");
			}
			else if (i%4 ==2)
			{
				temp.assign_rank(i%13);
				temp.assign_suit("Clubs");
			}
			else
			{
				temp.assign_rank(i%13);
				temp.assign_suit("Spades");
			}
		
			deck[i] = temp;
			
		}
	}
	
	//destructor
	Deck:: ~Deck()
	{
		delete[] deck;
	}
	
	void Deck::shuffle()
	{
		std::mt19937 g(static_cast<uint32_t>(time(0)));
		std::shuffle(&deck[0], &deck[cards], g);
	}

	std::string Deck::return_deck()
	{
		std::string deck_string;
		for (int i = 0; i < cards; i++)
		{
			deck_string = deck_string + "\n" + deck[i].return_card();
		}
		
		return deck_string;

	}

	int Deck::number_cards()
	{
		return cards;
	}	
	
	Card Deck::deal_card()
	{
		if (cards > 0)
		{
			cards = cards - 1;
			return deck[cards-1];
		}
		else
		{
			throw "No more cards in deck";
		}
	}
	
	void Deck::add_used_cards()
	{
		cards = total;
	}
		
