/*********************************************************************
** Program name: Project 2 turtle.cpp
** Author: NianJun Shi
** Date: April 22, 2019
** Description: This is the Turtle class implementation file. Turtle
				class represents a Turtle Animal at a zoo. It inherits
				from Animal class. Turtle class has five variables:
				foodCost - the cost of food
				age - age of the turtle
				cost - cost to buy a turtle
				numberofBabies - number of babies the turtle can have
				payoff - profit you make per turtle
				bonus - extra revenue per turtle
				Turtle class inherits the getter and setter functions
				for all variables except for food cost. It only has a
				getter function for foodCost since it calculates its 
				value from a constant. 
*********************************************************************/

#include "turtle.hpp"

Turtle::Turtle() : Animal()
{
	numberofBabies = 10 * Animal::numberofBabies;
	foodCost = 0.5 * Animal::BASEFOODCOST; 
	payoff = .05 * cost; 
}

Turtle::~Turtle()
{}

int Turtle::getFoodCost()
{
	return this->foodCost; 
}
