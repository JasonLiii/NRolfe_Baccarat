
#include "stdafx.h"
#include "Card.h"
#include <iostream>
#include <string>

Card::Card()
{
	//Default card is blank
	suit = "NULL";
	rank = 'X';
	value = 0;
}

Card::Card(char r, string s)
//Default constructor takes rank and string as input. Sets value according to rank
{
	suit = s;
	rank = r;
	if (rank == 'A')
		value = 1;
	if (rank == '2')
		value = 2;
	if (rank == '3')
		value = 3;
	if (rank == '4')
		value = 4;
	if (rank == '5')
		value = 5;
	if (rank == '6')
		value = 6;
	if (rank == '7')
		value = 7;
	if (rank == '8')
		value = 8;
	if (rank == '9')
		value = 9;
	if (rank == '1' || rank == 'J' || rank == 'Q' || rank == 'K')
		value = 0;
}

//Destructor
Card::~Card()
{
	//destructor
}

//Display method
void Card::display()
{	
	if (rank == '1'){
		cout << rank << "0 of " << suit;
	}
	else cout << rank << " of " << suit;
}

void Card::set_card(char r, string s)
{
	suit = s;
	rank = r;
	if (rank == 'A')
		value = 1;
	if (rank == '2')
		value = 2;
	if (rank == '3')
		value = 3;
	if (rank == '4')
		value = 4;
	if (rank == '5')
		value = 5;
	if (rank == '6')
		value = 6;
	if (rank == '7')
		value = 7;
	if (rank == '8')
		value = 8;
	if (rank == '9')
		value = 9;
	if (rank == '1' || rank == 'J' || rank == 'Q' || rank == 'K')
		value = 0;
}
//Accessor methods
int Card::get_value() { return value; }
char Card::get_rank() { return rank; }
string Card::get_suit() { return suit; }
