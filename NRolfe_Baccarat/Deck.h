#pragma once
#include "stdafx.h"
#include "Hand.h"
#include <iostream>

class Deck : public Hand
{
public:
	//Contructor Destructor
	Deck();
	~Deck();

	//Deck manipulators
	void build_deck(); //creates standard deck of playing cards. 52 cards, 4 suits
	void shuffle(); //Shuffles the deck into a random order
	void deal(Hand &h); //deals one card to a hand
	void display_deck(); //displays the deck
	int get_size(); //returns the current deck size
private:
	vector <Card*> deck;
};

