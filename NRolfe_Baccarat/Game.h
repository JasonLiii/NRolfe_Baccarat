#pragma once
#include "stdafx.h"
#include "Banker.h"
#include "Card.h"
#include "Deck.h"
#include "Generic_Player.h"
#include "Hand.h"
#include "Player.h" 

class Game
{
public:
	Game(); //Default constructor
	~Game(); //Destructor
	void play(); //Plays the game baccarat
	char playAgain();
private:
	Deck deck;
	Player p1;
	Banker b1;
	int tie, win, loss;
	int total_played;
};