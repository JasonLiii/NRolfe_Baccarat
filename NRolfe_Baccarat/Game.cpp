#include "stdafx.h"
#include "Game.h"
#include "Deck.h"
#include "Banker.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

Game::Game()
{
	//Default constructor
	tie = win = loss = total_played = 0;
}

Game::~Game()
{
	//Destructor
}

char Game::playAgain()
//returns user inputted 'y' or 'n' the play. This function contains all exception handling dealing with user input
{
	char p;
	bool unacceptable = true;

	//checks the user input for unwanted input. will res
	while (unacceptable)
	{
		cin >> p;
		try {
			if (p == 'y' || p == 'n')
				unacceptable = false;
			else
				throw 10;
		}
		catch (int i) {
			cout << "Thats an invalid input. Try 'y' or 'n'\n";
		}

	}
	return p;

}

void Game::play()
{
	//creates variables which will run the error checking and game loops
	char play;
	string name;

	//builds and shuffles the deck to be used in the game
	deck.build_deck();
	deck.shuffle();

	cout << "Hello human! Welcome to baccarat! Would you like to play? (y/n) : ";

	//Error checks the users input. throws an error if the user input is not 'y' or 'n'
	play = playAgain();

	if (play == 'y'){
		cout << "Before we go any further lets go over the rules!\n\nIn this version of Bacarrat the computer will do everything for you!\n"
			<< "\nThe object of the game is simple, get a hand with a higher value than me, the \nbanker.\n";
		cout << "\nFace cards and 10's have a value of 0, Ace has a value of 1 and number cards    have their face value.\n";
		cout << "\nYou will first be dealt two cards, as will I. If either of us is dealt a hand   with a value of 8 or 9, that is a natural and will automatically end the hand.\n";
		cout << "\nIf there is no natural, the computer will decide if you or I need to draw a     third card.\n"
			<< "The values of the two hands will then be compared to see who wins!\n";
		cout << "\nNow that that's out of the way let's get started! What's you name?\n";
		cin.ignore();
		getline(cin, name);
		p1.set_name(name);
	}

	//Starts the While loop which will play the game
	while (play == 'y')
	{
		//Deals out each hand alternating between the two. 
		deck.deal(p1);
		deck.deal(b1);
		deck.deal(p1);
		deck.deal(b1);

		//Displays both players hand after the deal
		cout << endl << name << "'s hand:\n";
		p1.display_hand();
		cout << "\nMy hand:\n";
		b1.display_hand();

		//Deals with case of naturals.
		if (p1.natural() && !b1.natural()){
			cout << endl << name << "! You have a natural!\n";
			cout << endl << name << "! You win this hand!\n";
			win++;
		}
		else if (b1.natural() && !p1.natural()){
			cout << "\nI have a natural!\n";
			cout << "\nI win this hand!\n";
			loss++;
		}
		//in the event of two naturals checks to see if one person has a higher natural. if not result is a tie
		else if (p1.natural() && b1.natural()){
			if (p1.get_total() > b1.get_total()){
				cout << endl << name << "! You win this hand!\n";
				win++;
			}
			else if (p1.get_total() < b1.get_total()){
				cout << "\nI win this hand!\n";
				loss++;
			}
			else {
				cout << "\nThere is a tie!!\n";
				tie++;
			}
		}

		//if the hand is not won with a natural game enters this structure
		else{
			//Checks to see if either player needs another card and deals one if needed
			if (p1.another_card(b1)){
				cout << endl << name << " you get another card.\n";
				deck.deal(p1);
				p1.display_hand();
			}
			if (b1.another_card(p1)){
				cout << "\nI get another card.\n";
				deck.deal(b1);
				b1.display_hand();
			}

			//Checks to see who wins the hand
			if (p1.win(b1)){
				cout << endl << name << " you win this hand!!\n";
				win++;
			}
			else if (p1.loser(b1)){
				cout << "\nI win this hand!!\n";
				loss++;
			}
			else {
				cout << "\nThere is a tie!\n";
				tie++;
			}
		}
		total_played++;

		//prints the total number of games played, how many each player won and how many ties there were
		cout << "\nOut of " << total_played << " hands " << name << " won " << win
			<< ", I won " << loss << " and there were " << tie << " ties!\n";


		//Clears each hand
		p1.clear();
		b1.clear();

		//Checks to see if the deck needs to be reshuffled. (under 8 cards)
		if (deck.get_size() <= 8){
			deck.clear();
			deck.build_deck();
			deck.shuffle();
		}

		//asks the user if thy would like to play again
		cout << "\nPlay Again?? (y/n)\n";
		//cin.ignore();
		play = playAgain();
	}
	cout << "\nGoodbye!!\n";
}