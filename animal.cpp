/*********************************************************************
** Program name: Project 2 animal.cpp
** Author: NianJun Shi
** Date: April 22, 2019
** Description: This is the Animal class implementation file. Animal
				class represents an animal at a zoo. Animal class has
				five variables:
				baseFoodCost - a constant, decribes the cost of food
				age - age of the animal
				cost - cost to buy an animal
				numberofBabies - number of babies the animal can have
				payoff - profit you make per animal 
				Each variable, except for baseFoodCost, has a setter
				and getting function.
				Lastly, hasAdult function is a flag function that
				returns a bool value if there is an adult animal.
*********************************************************************/

#include "animal.hpp"

//default constructor
Animal::Animal() 
{
	age = 1;
	cost = 100;
	numberofBabies = 1;
	payoff = 0; 
}

//destructor
Animal::~Animal()
{}

//define statis const value for food cost
//referenced https://stackoverflow.com/questions/2605520/c-where-to-initialize-static-const 
const int Animal::BASEFOODCOST = 10; 

void Animal::setAge(int inItAge)
{
	this->age = inItAge; 
}

void Animal::setCost(int inItCost)
{
	this->cost = inItCost;
}

void Animal::setBabies(int inItAmount)
{

	this->numberofBabies = inItAmount;
}

void Animal::setPayoff(int inItAmount)
{
	this->payoff = inItAmount; 
}

int Animal::getAge()
{
	return this->age; 
}

int Animal::getCost()
{
	return this->cost; 
}

int Animal::getFoodCost()
{
	return this->BASEFOODCOST;
}

int Animal::getBabies()
{
	return this->numberofBabies; 
}

int Animal::getPayoff()
{
	return this->payoff; 
}

/*********************************************************************
hasAdult function
** Description: This function looks for animal that is at least 3 days
				old. If one is found, returns the bool value of true. 
*********************************************************************/
bool Animal::hasAdult()
{
	bool hasAdult = false; 

	if (this->getAge() >= 3)
	{
		hasAdult = true;
	}

	return hasAdult; 
}