#include "stdafx.h"
#include "Hand.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

Hand::Hand()
{
}

void Hand::display_hand()
//Displays the current hand
{
	for (int i = 0; i < cards_held.size(); i++){
		cout << "Card " << i + 1 << ": ";
		cards_held[i]->display();
		cout << endl;
	}
}

void Hand::add(Card* c)
{
	cards_held.push_back(c);
}

int Hand::get_total()
{
	int total = 0;
	for (int i = 0; i < cards_held.size(); i++){
		total += cards_held[i]->get_value();
	}
	return (total % 10);
}

int Hand::get_third_card()
//returns the third card value
{
	try { 
		cards_held.at(2);
	}
	catch (const out_of_range& oor){
		return 0;
	}
	return cards_held.at(2)->get_value();
}

void Hand::clear()
{
	cards_held.clear();
}