/* Implementation of Player class for Blackjack game
*/

#include "player.h"

//Constructor

Player::Player(std::string nm)
{
	name = nm;
	winnings = 0;
	num_cards = 0;
}

Player::~Player()
{
}

void Player::accept_card(Card c)
{
	hand.vector::push_back(c);
}

void Player::release_cards()
{
	hand.vector::clear();
}

std::string Player::show_hand()
{
	if (hand.size() == 0)
	{
		return "Hand is empty";
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

double Player::show_winnings()
{
	return winnings;
}

void Player:: add_winnings(double num)
{
	winnings = winnings + num;
}
	
void Player:: subtract_winnings(double num)
{
	winnings = winnings - num;
}

int Player::return_num_cards()
{
	return hand.size();
}

std::string Player:: return_player_name()
{
	return name;
}

std::vector<Card> Player::return_hand()
{
	return hand;
}
