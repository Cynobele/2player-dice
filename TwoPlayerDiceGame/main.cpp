/*
Author : Cameron
Date : 22/06/2021

Project : A two player dice game

Rules : Each player takes turns rolling two dice, the total value that they get is added to a score
after 5 rounds, the player with the highest score wins. If a player rolls a double, they get to roll
a third dice, which is added to their score. If the player rolls an even total, they gain an extra
10 points, but if the player rolls an odd total, they lose 5 points. The players points should not
fall below 0.
*/

#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int rollDice(int currentScore)
{ //roll 2 dice for the player
	int total = 0;
	int extra = 0; //adds 0 to total if no double is rolled

	int x = rand() % 5 + 1; //get random number between 1 and 6
	int y = rand() % 5 + 1;

	if (x == y) //if the player rolls a double
	{
		extra = rand() % 5 + 1; //roll a third dice
		cout << "Double! Rolling a third dice..." << endl;
	}

	total = x + y + extra; //get the total value

	if (total % 2) //if total is odd
	{
		if (currentScore >= 0)//total cannot go below 0
		{
			cout << "Total is odd, you lose 5 points!" << endl;
			total -= 5; //subtract 5

			if (total < 0)
			{
				total = 0; // set total to 0
			}
		}
	}
	else
	{
		cout << "Total is even, you gain 10 points!" << endl;
		total += 10; //add 10
	}

	return total;
}


int main() {
	srand(time(NULL)); //seed the rand function

	int p1Total=0, p2Total=0;
	int round;

	for (round =0; round <5; round++) // 5 rounds in a game
	{
		cout << endl << "Round " << round+1 << endl;
		cout << "---------" << endl;

		cout << "Player 1 is rolling..." << endl; //get player 1 values
		p1Total = rollDice(p1Total);
		cout << "Player 1 has: " << p1Total << " points" << endl;

		cout << "Player 2 is rolling..." << endl; //get player 2 values
		p2Total = rollDice(p2Total);
		cout << "Player 2 has: " << p2Total << " points" << endl;
	}

	if (round == 5) //decide the winner
	{
		cout << endl << "The game is over." << endl;
		cout << "Player 1 : " << p1Total << " | Player 2 : " << p2Total; //print scores
		if (p1Total > p2Total)
		{
			cout << endl << "Player 1 has more points, they win!" << endl;
		}
		else if (p2Total > p1Total)
		{
			cout << endl << "Player 2 has more points, they win!" << endl;
		}
		else if (p1Total == p2Total)
		{
			cout << endl << "The game is a tie!" << endl;
		}
	}
	return 0;
}