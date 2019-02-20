/* Implementation of Dealer class for Blackjack game 
*/

#include "dealer.h"

Dealer:: Dealer(int decks)
{
	deck = new Deck(decks*52);
	int num_cards = 0;
	money = 0;
}
Dealer:: ~Dealer()
{
	delete deck;
}

void Dealer:: shuffle()
{
	deck -> shuffle();	
}

Card Dealer::deal_card()
{
	return deck -> deal_card();
}
void Dealer::accept_card(Card c)
{
	hand.vector::push_back(c);
}
void Dealer::release_cards()
{
	hand.vector::clear();
}
std::string Dealer::show_hand()
{
	if(hand.size() ==0)
	{
		return "Dealer hand is empty";
	}
	else
	{
		std::string string_hand = "";
		for (int i = 0; i < hand.size(); i ++)
		{
			string_hand = string_hand + hand[i].return_card() + "\n";
		}
		return string_hand;
	}
}

std::string Dealer::show_upcard()
{
	if(hand.size() == 0)
	{
		return "Dealer hand is empty";
	}
	else 
	{
		return hand[0].return_card();
	}
}

std::vector<Card> Dealer::return_hand()
{
	return hand;
}

void Dealer::add_money(double m)
{
	money = money + m;
}

void Dealer::subtract_money(double m)
{
	money = money - m;
}

double Dealer::return_money()
{
	return money;
}
