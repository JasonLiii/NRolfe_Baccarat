#pragma once
#include "stdafx.h"
#include "Hand.h"
#include <string>


class Generic_Player : public Hand 
{
public:
	bool virtual another_card(Generic_Player&) = 0; //Pure virtual function to determine if player gets another card
	bool natural(); //Determines if player has a natural
	void winner(Generic_Player&); //takes in other player, gets their hand value, determines if player who called function wins (true) else false

protected:
	string name;
};