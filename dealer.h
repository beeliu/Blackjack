#ifndef DEALER_H
#define DEALER_H
#include "deck.h"
#include <vector>

class Dealer
{
	private:
	
	Deck *deck;
	int num_cards;
	std::vector<Card> hand;
	double money;

	public:
	Dealer(int decks);
	~Dealer();
	void shuffle();
	Card deal_card();
	void accept_card(Card c);
	void release_cards();
	std::string show_hand();
	std::string show_upcard();
	std::vector<Card> return_hand();
	void add_money(double m);
	void subtract_money(double m);
	double return_money();
};

#endif
