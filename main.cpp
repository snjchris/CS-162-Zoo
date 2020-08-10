/*********************************************************************
** Program name: Project 2 main.cpp
** Author: NianJun Shi
** Date: April 22, 2019
** Description: This is the main function of Project 2. Project 2 is a
				simulation of the zoo tycoon game. It's purpose is
				to create a zoo class object and start the game by calling
				the zoo class startGame function. 
				The main function also generates a seed value that will
				help generate "random numbers".
*********************************************************************/

#include"zoo.hpp"
#include <ctime>
#include <cmath>

int main()
{
	Zoo save1; 

	//generate seed
	int seed = time(0);
	srand(seed);

	//start game
	save1.startGame(); 

	return 0;
}