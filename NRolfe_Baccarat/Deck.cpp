#include "stdafx.h"
#include "Deck.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

Deck::Deck()
{
}

Deck::~Deck()
{
	//Destructor
}

void Deck::build_deck()
/*builds a standard deck of playing cards from */
{
	string suit;
	char rank;
	

	//for loop places 
	for (int i = 0; i < 4; i++){
		if (i == 0)
			suit = "Spades";
		if (i == 1)
			suit = "Hearts";
		if (i == 2)
			suit = "Clubs";
		if (i == 3)
			suit = "Diamonds";
		for (int j = 0; j < 13; j++){
			if (j == 0)
				rank = 'A';
			else if (j == 1)
				rank = '2';
			if (j == 2)
				rank = '3';
			if (j == 3)
				rank = '4';
			if (j == 4)
				rank = '5';
			if (j == 5)
				rank = '6';
			if (j == 6)
				rank = '7';
			if (j == 7)
				rank = '8';
			if (j == 8)
				rank = '9';
			if (j == 9)
				rank = '1';
			if (j == 10)
				rank = 'J';
			if (j == 11)
				rank = 'Q';
			if (j == 12)
				rank = 'K';

			//temp card is set with values determined by loop iteration and then pushed into the vector
			Card* tempCard = new Card(rank, suit);
			deck.push_back(tempCard);
		}
	}

}

void Deck::shuffle()
{
	//creates a temporary card
	Card* tempCard = new Card();

	srand(static_cast<unsigned int>(time(0))); //seeds the random number generator to the clock
	for (int i = 0; i < 364; i++){
		//Creates random location to choose card from
		int randomLoc = rand() % 52;
		//sets the pointer to temp card equal to the pointer at the random location. 
		tempCard = deck[randomLoc];
		//pushes the tempCard
		deck.push_back(tempCard);
		deck.erase(deck.begin() + randomLoc);
	}
}

void Deck::deal(Hand &h)
//Deals one card into the hand passed to the function
{
	Card* tempCard = new Card();
	tempCard = deck.back();
	deck.erase(deck.begin()+(deck.size()-1));
	h.add(tempCard);
}

void Deck::display_deck()
//Runs a for loop for the size of the deck and utilizes the Card Class' display function
{
	for (int i = 0; i < deck.size(); i++){
		deck[i]->display();
		cout << endl;
	}
}

int Deck::get_size()
{
	return deck.size();
}
