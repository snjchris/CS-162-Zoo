/*********************************************************************
** Program name: Project 2 zoo.hpp
** Author: NianJun Shi
** Date: April 22, 2019
** Description: This is the zoo class specification file. Zoo class
				simulates the execution of the zoo typhon game. It has 
				eight variables: 
				cashBal - the amount of cash on hand available to spend
				day - day/turn number
				tigerCount - the number of tigers in the zoo
				pengCount - the number of penguins in the zoo
				turtCount - the number of turtles in the zoo
				maxTiger - the maximum number of tigers the array can hold
				maxPeng - the maximum number of penguins the array can hold
				maxTurt - the maximum number of turtles the array can hold
				The max_animal variables are there to determine if a new
				array should be allocated to store more animals.
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP
#include <string>
#include <fstream>
#include "penguin.hpp"
#include "tiger.hpp"
#include "turtle.hpp"

class Zoo
{
private:
	int cashBal,
		day,
		tigerCount,
		pengCount,
		turtCount,
		maxTiger,
		maxPeng,
		maxTurt;
	
	Tiger *tigList = nullptr; 
	Penguin *pengList = nullptr;
	Turtle *turtList = nullptr; 

public:
	Zoo();
	~Zoo(); 

	//setters
	void setCashBal(int);
	void setDay(int);

	//getters
	int	getCashBal();
	int getDay(); 

	//display animal count functions
	int getTotalAnimal();
	void displayAnimal(); 

	//income and cost functions
	int getIncome();
	int getTotalFoodCost(); 

	//withdraw cash function
	void spendCash(int);

	//increment animal size functions 
	void addTiger(int, int);
	void addPeng(int, int);
	void addTurt(int, int); 
	void increaseTigSize();
	void increasePengSize();
	void increaseTurtSize();

	//increase age
	void increaseAge(); 
	
	//random event functions 
	void genRandEvent();
	void sickEvent(std::ofstream &, std::ifstream &, std::string, int);
	void bonusEvent(std::ofstream &, std::ifstream &, std::string);
	void babyEvent(std::ofstream &, std::ifstream &, std::string, int);
	void noEvent(std::ofstream &, std::ifstream &, std::string);

	//menu functions
	void startGame();
	void buyMenu(); 
	void gameMenu(); 
	void buyAnimal();
	
	//input validation functions 
	int correct1ChoiceInput(std::string);
	int correct2ChoiceInput(std::string, std::string);
	int correct3ChoiceInput(std::string, std::string, std::string);
	char correctCharInput(std::string); 
};
#endif // !ZOO_HPP

