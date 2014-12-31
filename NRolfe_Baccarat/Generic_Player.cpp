#include "stdafx.h"
#include "Generic_Player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Generic_Player::natural()
{
	if (get_total() == 8 || get_total() == 9)
		return true;
	else return false;
}

void Generic_Player::winner(Generic_Player& p)
{
	cout << "Player wins!!\n";
}