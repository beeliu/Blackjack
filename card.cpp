/* Implementation file for Card class */

#include "card.h"

	Card::Card()
	{
		rank = -1;
		suit = "";
	}
	Card::Card(int r, std::string s)
	{
		// error checking
		if (r < 0 || r > 12)
		{
			throw std::exception();
		}	
		if (s != "Hearts" && s != "Diamonds" && s!= "Clubs" && s != "Spades")
		{
			throw std::exception();
		}
		else
		{
			rank = r;
			suit = s;
		}
	}

	Card::~Card()
	{

	}	
	void Card::assign_rank(int r)
	{
		if (r < 0 || r > 12)
		{
			throw std::exception();
		}
		else
		{
			rank = r;
		}
	}
	
	void Card::assign_suit(std::string s)
	{
		if (s != "Hearts" && s != "Diamonds" && s!= "Clubs" && s != "Spades")
		{
			throw std::exception();
		}
		else
		{
			suit = s;
		}
	}

	int Card::return_rank()
	{
		return rank;
	}

	std::string Card::return_suit()
	{		
		return suit;
	}

	std::string Card::return_card()
	{
		std::string card;
		
		//rank
		if (rank != 0 && rank < 10) // rank is number
		{
			card = std::to_string(rank+1) + " of ";
		}
		else if (rank == 0) // Ace
		{
			card = "Ace of ";
		}
		else if (rank == 10) // Jack
		{
			card = "Jack of ";
		}
		else if (rank == 11) // Queen 
		{
			card = "Queen of ";
		}
		else // King
		{
			card = "King of ";
		}

		// suit
		card = card + suit;
		return card;
		}


