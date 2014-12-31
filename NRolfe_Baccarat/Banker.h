#pragma once
#include "stdafx.h"
#include "Generic_Player.h"
#include "Player.h"
#include "Hand.h"

class Banker : public Generic_Player
{
public:
	//Constructor and destructor
	Banker();
	~Banker();

	//Determines if a nother card is needed
	bool virtual another_card(Generic_Player&);
};