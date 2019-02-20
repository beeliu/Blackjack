/*  File to test player class */

#include <iostream>
#include "player.h"

using namespace std;

int main()
{
	string name;
	cout << "What is your name?" << endl;
	cin >> name;

	//create new player
	Player player1(name);
	cout << player1.return_player_name() << endl;	

	Card card1(0, "Hearts");
	player1.accept_card(card1);
	cout << player1.show_hand() << endl;
	cout << player1.return_num_cards() << endl;

	Card card2(1, "Diamonds");
	player1.accept_card(card2);
	cout << player1.show_hand() << endl;
	cout << player1.return_num_cards() << endl;

	player1.add_winnings(200);
	player1.add_winnings(3.50);
	player1.subtract_winnings(150.25);
	cout << player1.show_winnings() << endl;
	
	player1.release_cards();
	cout << player1.show_hand() << endl;
	cout << player1.return_num_cards() << endl;

	
}
