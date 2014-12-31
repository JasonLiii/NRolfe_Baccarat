#include "stdafx.h"
#include "Banker.h"
#include <string>


using namespace std;

Banker::Banker()
{
	name = "Banker";
}

Banker::~Banker()
{
	//Banker destructor
}

bool Banker::another_card(Generic_Player& p)
{
	int third = p.get_third_card();
	if (get_total() <= 2)
		return true;
	if (get_total() == 3){
		if (third == 8)
			return false;
		else return true;
	}
	if (get_total() == 4){
		if (third == 1 || third > 9)
			return false;
		else return true;
	}
	if (get_total() == 5){
		if (third < 4 || third > 7)
			return false;
		else return true;
	}
	if (get_total() == 6){
		if (third == 6 || third == 7)
			return false;
		else return true;
	}
	if (get_total() == 7)
		return false;
}

