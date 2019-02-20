/* This is the test file for the dealer class
*/

#include "dealer.h"
#include <iostream>

using namespace std;

int main()
{
	int decks;
	cout << "How many decks would you like to play with?" << endl;
	cin >> decks;

	Dealer dealer1(decks);
	dealer1.shuffle();
	dealer1.accept_card(dealer1.deal_card());
	dealer1.accept_card(dealer1.deal_card());
	cout << dealer1.show_upcard() << endl;
	cout << dealer1.show_hand() << endl;
	
	dealer1.accept_card(dealer1.deal_card());
	cout << dealer1.show_hand() << endl;
	
	dealer1.release_cards();
	cout << dealer1.show_hand() << endl;		
}
