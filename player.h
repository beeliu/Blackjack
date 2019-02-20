#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>

class Player
{
	private:
	std::string name;
	double winnings;
	int num_cards;
	std::vector<Card> hand;
	
	public:
	Player(std::string nm);
	~Player();
	void accept_card(Card c);
	void release_cards();
	std::string show_hand();
	double show_winnings();
	void add_winnings(double num);
	void subtract_winnings(double num);
	int return_num_cards();
	std::string return_player_name();
	std::vector<Card> return_hand();	
	
	
};

#endif
