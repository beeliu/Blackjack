#ifndef DECK_H_
#define DECK_H_

#include <algorithm>
#include <random>
#include "card.h"

class Deck
{
	private:
	Card *deck;
	int cards;
	int total;

	public:
	Deck(int number_cards);
	~Deck();
	void shuffle();
	std::string return_deck();
	int number_cards();
	Card deal_card();
	void add_used_cards();
};

#endif
