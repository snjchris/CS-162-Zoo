/*********************************************************************
** Program name: Project 2 animal.hpp
** Author: NianJun Shi
** Date: April 22, 2019
** Description: This is the Animal class specification file. Animal
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

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
protected:
	static const int BASEFOODCOST;
	int age,
		cost,
		numberofBabies,
		payoff;

public:
	Animal();
	~Animal(); 
 
	//setters
	void setAge(int); 
	void setCost(int);
	void setBabies(int);
	void setPayoff(int); 
	
	//getters
	int getFoodCost(); 
	int getAge();
	int getCost(); 
	int getBabies();
	virtual int getPayoff();


	 
	bool hasAdult(); 

};
#endif // !ANIMAL_HPP

