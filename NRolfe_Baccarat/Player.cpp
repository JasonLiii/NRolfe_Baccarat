#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Player::Player()
{
	name = "Player";
}

Player::~Player()
{
	//Destructor
}

bool Player::another_card(Generic_Player& p)
{
	if (get_total() <= 5)
		return true;
	else if (get_total() >= 6)
		return false;
}

bool Player::win(Generic_Player &b)
//returns true if the player lost the hand
{
	if (get_total() > b.get_total())
		return true;
	else return false;
}

bool Player::loser(Generic_Player &b)
//returns true if the player lost the hand
{
	if (get_total() < b.get_total())
		return true;
	else return false;
}

void Player::set_name(string n)
//sets name of player
{
	name = n;
}
