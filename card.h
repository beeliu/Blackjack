#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
	private:
	int rank;
	std::string suit;

	public:
	Card();
	Card(int r, std::string s);
	~Card();
	void assign_rank(int r);
	void assign_suit(std::string s);
	int return_rank();
	std::string return_suit();
	std::string return_card();
};

#endif
