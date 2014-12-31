#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class Card
{
public:
	//Constuctors
	Card();
	Card(char, string);

	//destructor
	~Card();

	//Accessor methods
	int get_value();
	char get_rank();
	string get_suit();

	//Mutator
	void set_card(char , string);

	//Display method
	void display(); //will be called when displaying the hand or deck

	

private:
	char rank; //Face value of the card
	int value; //Value used in baccarat
	string suit; //Suit of the card
};