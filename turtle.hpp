/*********************************************************************
** Program name: Project 2 turtle.hpp
** Author: NianJun Shi
** Date: April 22, 2019
** Description: This is the Turtle class specification file. Turtle
				class represents a turtle animal at a zoo. It inherits
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

#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "animal.hpp"

class Turtle : public Animal
{
private:
	int foodCost;

public:
	Turtle();
	~Turtle(); 

	int getFoodCost();
};
#endif 

