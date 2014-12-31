#pragma once
#include "stdafx.h"
#include "Card.h"
#include <iostream>
#include <vector>

using namespace std;

class Hand
{
public:
	Hand();
	void add(Card* c); //Adds a card by adding a pointer to a card object to the vector of cards representing the hand
	void clear(); //clears the hand and cleans up all deleted objects
	int get_total(); //returns the total value of the hand
	void display_hand(); //Displays the current hand
	int get_third_card();
protected:
	vector <Card*> cards_held;
};