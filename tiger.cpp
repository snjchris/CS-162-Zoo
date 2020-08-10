/*********************************************************************
** Program name: Project 2 Tiger.cpp
** Author: NianJun Shi
** Date: April 22, 2019
** Description: This is the Tiger class implementation file. Tiger class
				represents a tiger animal at a zoo. It inherits
				from Animal class. Tiger class has five variables:
				foodCost - the cost of food
				age - age of the tiger
				cost - cost to buy a tiger
				numberofBabies - number of babies the tiger can have
				payoff - profit you make per tiger
				bonus - extra revenue per tiger
				Tiger class inherits the getter and setter functions
				for all variables except for food cost. It has its own
				getter and setter functions for foodCost and bonus. In 
				addition, it has its own getPayoff function since the
				tiger's payoff is payoff + any applicable bonus.
*********************************************************************/
#include "tiger.hpp"

//default constructor
Tiger::Tiger() : Animal()
{	
	foodCost = Animal::BASEFOODCOST * 5;
	cost = 100 * Animal::cost;
	payoff = .2 * cost;
	bonus = 0; 
}

//destructor
Tiger::~Tiger()
{}

void Tiger::setBonus(int inItBonus)
{
	this->bonus = inItBonus; 
}

int Tiger::getFoodCost()
{
	return foodCost;
}

/*********************************************************************
getPayoff function
** Description: Function returns the payoff as base payoff + bonus 
*********************************************************************/
int Tiger::getPayoff()
{
	return (this->payoff + this->bonus);
}

int Tiger::getBonus()
{
	return this->bonus; 
}