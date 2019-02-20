/* Game implementation of Blackjack, contains main function
*/

#include <iostream>
#include <sstream>
#include <unistd.h>
#include "player.h"
#include "dealer.h"

using namespace std;

// Payout: 3:2 blackjack
//	   1:1 win
//         0   lose
//         keep bet if tie

//helper function to calculate value of hand
int sum_cards(vector<Card> cards);

int main()
{
	// creates betting pool
	double pool = 0;
	
	//Introduction
	
	cout << "Welcome to Blackjack!" << endl;
	string name;
	cout << "What is your name?" << endl;
	getline(cin,name);
	Player player1(name);
	cout << "Welcome " + player1.return_player_name() + "!" << endl;
 	int decks;
	bool ask_decks1 = true;
	do
	{
		if (ask_decks1 == true)
		{
			cout << "How many decks would you like to play with? (Choose between 1 and 10)" << endl;
			ask_decks1 = false;
		}
		else
		{
			cout << "Please enter a number between 1 and 10" << endl;
		}
		cin >> decks;
	}
	while (decks < 1 || decks > 10);
	Dealer dealer(decks);
	
	//shuffle cards
	dealer.shuffle();
	
	//player buys-in
	double buy_in;
	bool ask_buyin = true;
	do
	{
		if (ask_buyin == true)
		{
			cout << "How much would you like to buy in for? (Dollar amount between 1 and 1000)" << endl;
			ask_buyin = false;
		}
		else 
		{
			cout << "Please enter dollar amount between 1 and 1000" << endl;
		}
		cin >> buy_in;
	}
	while (buy_in <= 0 || buy_in > 1000);
	player1.add_winnings(buy_in);
	cout << "You have ";
	cout << player1.show_winnings(); 
	cout << " to play with." << endl;	

	//continues while player still wants to play game
	bool cont = true;
	double bet = 0;
	do
	{
		bool ask1 = true;
		do
		{
			if (ask1)
			{
				cout << "How much would you like to bet for this round? (Enter dollar amount)" << endl;
				ask1 = false;
			}
			else
			{
				cout << "You don't have enough money, please enter a smaller amount" << endl;
			}
			cin >> bet;
		}
		while (player1.show_winnings() - bet < 0);
		player1.subtract_winnings(bet);		

		// while neither player or dealer has lost yet
		bool player_in = true;
		bool dealer_in = true;
		bool player_blackjack = false;
		bool dealer_blackjack = false;

		//dealer is dealt 2 cards and player is dealt 2 cards
		dealer.accept_card(dealer.deal_card());
		dealer.accept_card(dealer.deal_card());
		player1.accept_card(dealer.deal_card());
		player1.accept_card(dealer.deal_card());
	
		// reveal dealer upcard
		cout << "\n Dealer's upcard is: " + dealer.show_upcard() + "\n" << endl;
		sleep(2);
		
		// PLAYER  moves first
		cout << "Your hand is: \n"; 
		sleep(1);
		cout << player1.show_hand() << endl;
		sleep(2);

		bool player_playing = true;	
		// checks for blackjack
		if (sum_cards(player1.return_hand()) == 21)
		{
			cout << "Congratulations, you got blackjack!" << endl;
			sleep(2);
			player_blackjack = true;	
			player_playing = false;
		}
		// else can make another move
		{
			while (player_playing == true) 
			{
				string next_move = "";
				bool first_ask = true;
				do
				{
					if (first_ask)
					{
						cout << "What is your move? (hit, stand, double-down)" << endl;
						first_ask = false;
					}
					else
					{
						cout << "Please choose hit, stand, or double-down" << endl;
					}
					cin >> next_move;
				}
				while (next_move != "hit" && next_move != "stand" && next_move != "double-down");			
				sleep(2);				

				if (next_move == "hit")
				{
					player1.accept_card(dealer.deal_card());
				}
				else if (next_move == "stand")
				{
					player_playing = false;
				}
				else
				{
					double new_bet;
					string increase;
					bool first_ask1 = true;
					do 
					{
						if (first_ask1)
						{
							cout << "Would you like to increase bet? (yes/no)" << endl;
							first_ask1 = false;
						}
						else 
						{
							cout << "Please answer yes or no" << endl;
						}
						cin >> increase;
					}		
					while (increase != "yes" && increase != "no");
		
					if (increase == "yes")
					{
						cout << "What would you like to bet? (Please enter dollar amount)" << endl;
						cin >> new_bet;
					}
						
					bet = bet + new_bet;
					player1.accept_card(dealer.deal_card());
					player_playing = false;
					
				}

				cout << "\nYour hand is: \n" + player1.show_hand() << endl;					
				sleep(2);
	
				int sum = sum_cards(player1.return_hand());
				if (sum > 21)
				{
					cout << "Sorry, you lost!" << endl;
					sleep(2);
					player_in = false;
					player_playing = false;
					dealer.add_money(bet);
					cout << "Dealer takes ";
					cout << bet << endl;
					cout << "You now have ";
					cout << player1.show_winnings();
					cout << " to play with. \n";
					sleep(2);
					bet = 0;
				}	
				if (sum == 21)
				{
					cout << "Congratulations, you got blackjack!" << endl;
					sleep(2);
					player_playing = false;
					player_blackjack = true;
				}
				
			}

		}		

		// DEALER moves 
		if (dealer_in != false && player_in != false)
		{
			// reveal other card
			cout << "Dealer's hand: \n" + dealer.show_hand() + "\n"  << endl;
			sleep(2);
	
			int dealer_value = sum_cards(dealer.return_hand());
			
			bool playing = true;
			if (dealer_value == 21)
			{
				cout << "Dealer wins blackjack" << endl;
				sleep(2);
				dealer_blackjack = true;
				playing = false;
			}
			else
			{	
				while (playing == true)
				{
					dealer_value = sum_cards(dealer.return_hand());
					// must hit if <17, stand if 17 or higher
					if (dealer_value < 17)
					{
						cout << "\n Dealer hits\n" << endl;
						sleep(2);
						dealer.accept_card(dealer.deal_card());
					}
					else
					{
						cout << "\n Dealer stands\n" << endl;
						sleep(2);	
						playing = false;
					}
			
					cout << "Dealer's hand: \n" + dealer.show_hand() + "\n" << endl;
					sleep(2);

					int dealer_sum = sum_cards(dealer.return_hand());
					if (dealer_sum == 21)
					{
						cout << "Dealer has blackjack. \n";
						sleep(2);
						dealer_blackjack = true;
						playing = false;						
					}
					else if (dealer_sum > 21)
					{
						cout << "Dealer loses. \n";
						sleep(2);
							
						dealer_in = false;
						playing = false;
						
						if (player_blackjack == false)
						{
							player1.add_winnings(bet);
							cout << "You win ";
							cout << bet;
							cout << "\nNow you have ";
							cout << player1.show_winnings();
							cout << " to play with.\n"<< endl;
							bet = 0;
							sleep(2);
						}
					}
				}
			}

		}
		
		// if both player and dealer did not bust, check to see who has higher value hand
		if (dealer_in == 1 && player_in == 1 && !(dealer_blackjack == true || player_blackjack == true))
		{		
			int player_value = sum_cards(player1.return_hand());
			int dealer_value = sum_cards(dealer.return_hand());
			if (player_value > dealer_value)
			{
				cout << "You have a higher value hand than the dealer, you win ";
				cout << bet;
				player1.add_winnings(bet);	
				cout << "/n You now have "; 
				cout << player1.show_winnings();
				cout << " to play with.\n" << endl;
				bet = 0; 
				sleep(2);
			}
			else if (player_value < dealer_value)
			{
				cout << "Dealer has higher value hand than you" << endl;
				dealer.add_money(bet);
				cout << "Dealer collects ";
				cout <<  bet << endl;
				cout << "\n";
				cout << "\nNow you have ";
                                cout << player1.show_winnings();
                                cout << " to play with.\n"<< endl;
				bet = 0;
				sleep(2);
			}
			else
			{
				cout << "Tie between player and dealer\n" << endl;
				sleep(2);
			}
		}
		if (dealer_blackjack == true && player_blackjack == true)
		{
			cout << "Both you and dealer have blackjack: tie \n" << endl;
			sleep(2);
		}
		if (dealer_blackjack == true && player_blackjack == false)
		{
			cout << "Dealer has blackjack and wins.\n" << endl;
			dealer.add_money(bet);
			cout << "Dealer collects ";
			cout << bet << endl;
			cout << "\n";
			cout << "\nNow you have ";
                        cout << player1.show_winnings();
                        cout << " to play with.\n"<< endl;
			bet = 0;
			sleep(2);
		}
		if (player_blackjack == true && dealer_blackjack == false)
		{
			cout << "You have blackjack and you win!\n" << endl;
			player1.add_winnings(bet*(1.5));
			cout << "You collect ";
			cout << bet*(1.5); 
			cout << " and have "; 
			cout <<  player1.show_winnings();
			cout << " total to play with.\n" << endl;
			bet = 0;
			sleep(2);
		}

		string another_round;
		bool first_ask2 = true;
		do
		{
			if (first_ask2)
			{
				cout << "Would you like to play another round? (yes/no)" << endl;
				first_ask2 = false;
			}
			else
			{
				cout << "Please enter yes or no" << endl;
			}
			cin >> another_round;
		}
		while (another_round != "yes" && another_round != "no");
		if (another_round == "no" || player1.show_winnings() <= 0)
		{
			cont = 0;
		}
		else
		{
			// clear hands
			player1.release_cards();
			dealer.release_cards();
		}
	}
	while (cont == 1);

	return 0;	
}

int sum_cards(vector<Card> cards)
{
	int sum = 0;
	int aces = 0;
	for (int i = 0; i < cards.size(); i ++)
	{
		int card_value = cards[i].return_rank() + 1;

		// pip value cards
		if (card_value != 1 && card_value != 11 && card_value != 12 && card_value != 13)
		{
			sum = sum + card_value;
		} 	
		// if face cards value is 10
		else if (card_value == 11 || card_value == 12 || card_value == 13)
		{
			sum = sum + 10;
		}	
		// if card is ace
		else
		{
			aces = aces + 1;
		}
	}

	// determine if ace cards should be hard or soft
	for (int j = 0; j < aces; j++)
	{
		if ( (sum + 11) > 21)
		{
			sum = sum + 1;
		}
		else
		{
			sum = sum + 11;
		}
	}
	
	return sum;
}
