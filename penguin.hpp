/*********************************************************************
** Program name: Project 2 penguin.hpp
** Author: NianJun Shi
** Date: April 22, 2019
** Description: This is the Penguin class specification file. Penguin 
				class represents a penguin animal at a zoo. It inherits
				from Animal class. Penguin class has five variables:
				foodCost - the cost of food
				age - age of the penguin
				cost - cost to buy a penguin
				numberofBabies - number of babies the penguin can have
				payoff - profit you make per penguin
				Penguin class inherits the getter and setter functions
				for all variables except for food cost. 
*********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "animal.hpp"

class Penguin : public Animal
{
private: 
	int foodCost;

public:
	Penguin();
	~Penguin(); 

	//getter
	int getFoodCost();
};
#endif // 

