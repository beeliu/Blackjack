#include <iostream>
#include "card.h"

using namespace std;

int main()
{
	try{
	// make real cards
	Card card1(0, "Hearts");
	cout << card1.return_card() << endl;

	Card card2(12, "Diamonds");
	cout << card2.return_card() << endl;

	Card card3(1, "Spades");
	cout << card3.return_card() << endl;

	Card card4(10, "Clubs");
	cout << card4.return_card() << endl;

	// change card 
	card4.assign_rank(5);
	cout << card4.return_rank() << endl;
	cout << card4.return_suit() << endl;
	
	card4.assign_suit("Spades") ;
	cout << card4.return_card() << endl;

	}
	catch (exception & e)
	{
		cout << "Error in first block" << endl;
	}
	//checks if exceptions work
	try
	{
		Card card5(-1, "Spades"); 
	}
	catch (exception& e1)
	{
		cout << "rank out of range" << endl; 
	}
	try
	{
		Card card6(1, "diamond");
	}
	catch(exception& e2)
	{
		cout << "not a valid suit" << endl;
	}
	try
	{
		Card card7(2, "Spades");
		card7.assign_rank(13);
	}
	catch(exception& e3)
	{
		cout << "assign_rank failed" << endl;
	}
	try 
	{
		Card card8(3, "Diamonds");
		card8.assign_suit("spade");
	}
	catch(exception & e4)
	{
		cout << "assign_suit failed" << endl;
	}
	
}
