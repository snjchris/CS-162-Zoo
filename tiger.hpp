/*********************************************************************
** Program name: Project 2 tiger.hpp
** Author: NianJun Shi
** Date: April 22, 2019
** Description: This is the Tiger class specification file. Tiger class
				represents a tiger animal at a zoo. It inherits
				from Animal class. Tiger class has five variables:
				foodCost - the cost of food
				age - age of the tiger
				cost - cost to buy a tiger
				numberofBabies - number of babies the tiger can have
				payoff - profit you make per tiger
				bonus - extra revenue per tiger
				Tiger class inherits the getter and setter functions
				for all variables except for food cost. Food cost only
				has a getter function since it calculates its value from
				a constant. It has its own getter and setter functions 
				for bonus. In addition, it has its own getPayoff function 
				since the tiger's payoff is payoff + any applicable bonus. 
*********************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP
#include "animal.hpp"

class Tiger : public Animal
{
private:
	int foodCost,
		bonus;
public: 
	Tiger();
	~Tiger(); 

	//setter
	void setBonus(int); 
	
	//getters
	int getFoodCost();
	virtual int getPayoff() override;
	int getBonus(); 
};

#endif // !TIGER_HPP

