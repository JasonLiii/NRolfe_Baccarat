#pragma once
#include "stdafx.h"
#include "Generic_Player.h"
#include <string>

class Player : public Generic_Player
{
public:
	//Constructor & Destructor
	Player();
	~Player();

	//Methods
	bool virtual another_card(Generic_Player&); //Determines if player gets another card
	bool win(Generic_Player&);
	bool loser(Generic_Player&);
	void set_name(string);
};