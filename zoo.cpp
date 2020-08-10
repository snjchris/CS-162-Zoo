/*********************************************************************
** Program name: Project 2 zoo.cpp
** Author: NianJun Shi
** Date: April 22, 2019
** Description: This is the Zoo class implementation file. Zoo class
				simulates the execution of the zoo typhon game.
*********************************************************************/

#include "zoo.hpp"
#include <string>
#include <iostream>
#include <fstream>

//default constructor
Zoo::Zoo()
{
	cashBal = 100000;
	day = 0;
	tigerCount = 0;
	pengCount = 0;
	turtCount = 0;
	maxTiger = 10;
	maxPeng = 10; 
	maxTurt = 10;
	tigList = new Tiger[10];
	pengList = new Penguin[10];
	turtList = new Turtle[10]; 
}

//destructor
Zoo::~Zoo()
{
	delete[] tigList;
	delete[] pengList;
	delete[] turtList;
}

void Zoo::setCashBal(int inItAmount)
{
	this->cashBal = inItAmount;
}

void Zoo::setDay(int inItDay)
{
	this->day = inItDay;
}

int Zoo::getCashBal()
{
	return this->cashBal;
}

int Zoo::getDay()
{
	return this->day;
}

/*********************************************************************
getTotalAnimal function
** Description: Function calculates the total number of animals by
				adding up the total of an types of animals. Return
				the int value.
*********************************************************************/
int Zoo::getTotalAnimal()
{
	return (tigerCount + pengCount + turtCount);
}

/*********************************************************************
displayAnimal function
** Description: This function displays how many animals are in the zoo,
				separated by the type of animal.
*********************************************************************/
void Zoo::displayAnimal()
{
	std::string desc = "You have ";

	std::cout << desc << tigerCount << " tiger(s).\n";
	std::cout << desc << pengCount << " penguin(s).\n";
	std::cout << desc << turtCount << " turtle(s).\n";
}

/*********************************************************************
getIncome function
** Description: Function returns an int income value by calculating and
				adding up each animal's payoff * count. 
*********************************************************************/
int Zoo::getIncome()
{
	return (tigerCount * tigList->getPayoff() + pengCount * pengList->getPayoff() + turtCount * turtList->getPayoff()); 
}

/*********************************************************************
getTotalFoodCost function
** Description: Function to calculate total food cost of all animals.
				It calls the getFoodCost function of each animal class
				then adds them together to get total food cost.
				Returns the total food cost value as an integer.
*********************************************************************/
int Zoo::getTotalFoodCost()
{
	return (tigerCount * tigList->getFoodCost() + pengCount * pengList->getFoodCost() + turtCount * turtList->getFoodCost());
}

/*********************************************************************
spendCash function
** Description: Function accepts an int parameter, assuming it is cost
				and deducts that value from the cash balance. 
*********************************************************************/
void Zoo::spendCash(int inItCost)
{
	this->cashBal -= inItCost;
}

/*********************************************************************
addTiger function
** Description: Function adds X number of tigers to the zoo. It accepts
				two integer parameters, one being the number to add to
				count and the other being the age of the animal. Before
				adding, it checks to see if the new proposed count is
				greater than the size of the array holding the animals.
				If yes, it calls the increaseTigSize function to first
				increase the size of the array. At the end, it adds the
				animals to the count and set their age to the passed
				number.
*********************************************************************/
void Zoo::addTiger(int inItNum, int inItAge)
{
	int currentNum = tigerCount,		//current number of tigers
		newNum = tigerCount + inItNum;	//new number of tigers 

	//checks to see if new number is greater than array size
	if (newNum > maxTiger)
	{
		//if yes, call function to increase array size
		increaseTigSize();
	}

	//increase tiger count
	tigerCount = newNum;

	//set age of the new tigers 
	for (int i = currentNum; i < newNum; i++)
	{
		tigList[i].setAge(inItAge);
	}
}

/*********************************************************************
addPeng function
** Description: Function adds X number of penguins to the zoo. It accepts
				two integer parameters, one being the number to add to
				count and the other being the age of the animal. Before
				adding, it checks to see if the new proposed count is
				greater than the size of the array holding the animals.
				If yes, it calls the increasePengSize function to first
				increase the size of the array. At the end, it adds the
				animals to the count and set their age to the passed
				number.
*********************************************************************/
void Zoo::addPeng(int inItNum, int inItAge)
{
	int currentNum = pengCount,			//current number of penguins
		newNum = pengCount + inItNum;	//new number of penguins

	//checks to see if new number is greater than array size
	if (newNum > maxPeng)
	{
		//if yes, call function to increase array size
		increasePengSize();
	}

	//increase penguin count
	pengCount = newNum;

	//set age of the new penguins
	for (int i = currentNum; i < newNum; i++)
	{
		pengList[i].setAge(inItAge);
	}
}

/*********************************************************************
addTurt function
** Description: Function adds X number of turtles to the zoo. It accepts
				two integer parameters, one being the number to add to
				count and the other being the age of the animal. Before
				adding, it checks to see if the new proposed count is
				greater than the size of the array holding the animals.
				If yes, it calls the increaseTurtSize function to first
				increase the size of the array. At the end, it adds the
				animals to the count and set their age to the passed
				number.
*********************************************************************/
void Zoo::addTurt(int inItNum, int inItAge)
{
	int currentNum = turtCount,			//current number of turtles
		newNum = turtCount + inItNum;	//new number of turtles

	//checks to see if new number is greater than array size
	if (newNum > maxTurt)
	{
		//if yes, call function to increase array size
		increaseTurtSize();
	}

	//increase turtle count
	turtCount = newNum;

	//set age of the new turtles
	for (int i = currentNum; i < newNum; i++)
	{
		turtList[i].setAge(inItAge);
	}
}

/*********************************************************************
increaseTigSize function
** Description: Function is called only when the proposed new number of
				tigers is greater than the current array's size (maxTiger).
				It dynamically allocates a new array that is twice the 
				size and then assigns the new array as the old array. 
*********************************************************************/
void Zoo::increaseTigSize()
{
	//first save the current number of tigers 
	int oldSize = tigerCount;

	Tiger * tempArray = nullptr; 

	//increase array size by 2
	maxTiger *= 2; 

	//allocate memory for temporary array, twice the size
	tempArray = new Tiger[maxTiger]; 

	//copy all existing tiger array to temporary array
	for (int i = 0; i < oldSize; i++)
	{
		tempArray[i] = tigList[i];
	}

	//delete old array
	delete[] tigList; 

	//assign old to temporary array 
	tigList = tempArray; 
}

/*********************************************************************
increasePengSize function
** Description: Function is called only when the proposed new number of
				penguins is greater than the current array's size (maxPeng).
				It dynamically allocates a new array that is twice the
				size and then assigns the new array as the old array.
*********************************************************************/
void Zoo::increasePengSize()
{
	//first saves the current number of penguins
	int oldSize = pengCount; 

	//increase array size by 2
	maxPeng *= 2; 

	Penguin *tempArray = nullptr; 

	//allocate memory for temporary array, twice the size
	tempArray = new Penguin[maxPeng];

	//copy all existing penguin's list to temporary array
	for (int i = 0; i < oldSize; i++)
	{
		tempArray[i]=pengList[i];
	}

	//delete old array
	delete[] pengList; 

	//assign old to temporary array
	pengList = tempArray; 

}

/*********************************************************************
increaseTurtSize function
** Description: Function is called only when the proposed new number of
				turtles is greater than the current array's size (maxTurt).
				It dynamically allocates a new array that is twice the
				size and then assigns the new array as the old array.
*********************************************************************/
void Zoo::increaseTurtSize()
{
	//first saves the current number of turtles
	int oldSize = turtCount;

	//increase array size by 2
	maxTurt *= 2; 

	Turtle *tempArray = nullptr; 

	//allocate memory for temporary array, twice the size
	tempArray = new Turtle[maxTurt]; 

	//copy all existing turtle array to temporary array
	for (int i = 0; i < oldSize; i++)
	{
		tempArray[i] = turtList[i];
	}

	//delete old array
	delete[] turtList;

	// assign old to temporary array
	turtList = tempArray; 
}

/*********************************************************************
increaseAge function
** Description: Function increases the age of every animal in the zoo 
				by 1. Also prints out the new age of all animals. 
*********************************************************************/
void Zoo::increaseAge()
{
	//variable to store animal's age
	int age = 0; 

	//increment and display all tigers' age
	std::cout << "Tigers' age: "; 
	for (int i = 0; i < tigerCount; i++)
	{
		age = tigList[i].getAge();
		age += 1;
		tigList[i].setAge(age); 
		std::cout << tigList[i].getAge() << " "; 
	}

	//reset age to 0
	age = 0; 

	//increment and display all penguins' age
	std::cout << "\nPenguins' age: ";
	for (int i = 0; i < pengCount; i++)
	{
		age = pengList[i].getAge();
		age += 1;
		pengList[i].setAge(age);
		std::cout << pengList[i].getAge() << " "; 
	}
	
	//reset age to 0
	age = 0; 

	//increment and display all turtles' age
	std::cout << "\nTurtles' age: ";
	for (int i = 0; i < turtCount; i++)
	{
		age = turtList[i].getAge();
		age += 1;
		turtList[i].setAge(age);
		std::cout << turtList[i].getAge() << " "; 
	}

	//white space
	std::cout << "\n"; 
}

/*********************************************************************
genRandEvent function
** Description: Function generates a random event using a random number
				generator. Some random events also select a random 
				animal so a random animal is also selected. The function
				also opens a file to allow the writing of the event
				outcome. 
*********************************************************************/
void Zoo::genRandEvent()
{
	//define fstream file objects
	std::ofstream writeFile;
	std::ifstream readFile; 

	//name of file to write and read from
	std::string outFilename = "status.txt";

	//variables to store the selected random event and random animal
	int randEvent = 0,
		randAnimal = 0;

	//open file; if there is already a file with the same name, wipe data
	writeFile.open(outFilename, std::ios::out);

	//cannot open file
	while (writeFile.fail())
	{
		std::cout << "Cannot open " << outFilename << " .\n";
		std::cout << "Please re-enter filename to write to: ";
		std::cin >> outFilename;
		writeFile.open(outFilename, std::ios::out);
	}

	//reset tiger's bonus to 0
	tigList->setBonus(0);

	//generate random event
	randEvent = rand() % 4 + 1; 

	//select a random animal type
	//1 is tiger, 2 is penguin and 3 is turtle
	randAnimal = rand() % 3 + 1;

	//call corresponding random event
	if (randEvent == 1)
	{
		sickEvent(writeFile, readFile, outFilename, randAnimal); 
	}

	else if (randEvent == 2)
	{
		bonusEvent(writeFile, readFile, outFilename);
	}

	else if (randEvent == 3)
	{
		babyEvent(writeFile, readFile, outFilename, randAnimal); 
	}
	
	else
	{
		noEvent(writeFile, readFile, outFilename);
	}
}

/*********************************************************************
sickEvent function
** Description: Random event #1. Functions kills off the selected 
				random animal. If no such animal exists, select 
				another available animal to kill off. 
				It accepts four parameters, the first two being
				fstream objects, the third being filename and lastly
				the selected random animal type. 
				For every outcome in this event, a status message
				is written to file and read from it. 
*********************************************************************/
void Zoo::sickEvent(std::ofstream & outFileObj, std::ifstream & readFileObj, std::string inItFileName, int inItAnimalType)
{
	//variable to store another type of animal in case the random animal doesn't exist
	int newAnimalType = 0;

	//variable to store message read from file 
	std::string message;

	//if tiger is chosen 
	if (inItAnimalType == 1)
	{
		//if there are no tigers, select another animal
		if (tigerCount == 0)
		{
			//select new animal type, between penguin and turtle
			newAnimalType = rand() % 2 + 1; 

			//if penguin is selected as the new animal type
			if (newAnimalType == 1)
			{
				//if there are also no penguins, remove one turtle
				if (pengCount == 0)
				{
					turtCount -= 1;
					//write status message to file
					outFileObj << "A turtle died today due to sickness. You now have " << turtCount << " turtle(s)."; 
				}
				//if there are penguins, remove a penguin
				else
				{
					pengCount -= 1; 
					//write status message to file
					outFileObj << "A penguin died today due to sickness. You now have " << pengCount << " penguin(s).";
				}
			}	
			//if turtle is selected
			else
			{
				//if there are no turtles, remove a penguin
				if (turtCount == 0)
				{
					pengCount -= 1;
					//write status message to file
					outFileObj << "A penguin died today due to sickness. You now have " << pengCount << " penguin(s).";
				}

				//if there are turtles, remove a turtle
				else
				{
					turtCount -= 1;
					//write status message to file
					outFileObj << "A turtle died today due to sickness. You now have " << turtCount << " turtle(s).";
				}
			}
		}

		//if there are tigers, remove one tiger
		else
		{
			tigerCount -= 1; 
			//write status message to file
			outFileObj << "A tiger died today due to sickness. You now have " << tigerCount << " tiger(s).";
		}
	}
	//if penguin is chosen
	else if (inItAnimalType == 2)
	{
		//if there are no penguins 
		if (pengCount == 0)
		{
			//select new animal type, between tiger and turtle
			newAnimalType = rand() % 2 + 1;

			//if tiger is selected as the new animal type 
			if (newAnimalType == 1)
			{
				//if there are no tigers, remove a turtle
				if (tigerCount == 0)
				{
					turtCount -= 1;
					//write status message to file
					outFileObj << "A turtle died today due to sickness. You now have " << turtCount << " turtle(s).";
				}
				//if there are tigers, remove a tiger
				else
				{
					tigerCount -= 1;
					//write status message to file
					outFileObj << "A tiger died today due to sickness. You now have " << tigerCount << " tiger(s).";
				}
			}
			//if turtle is selected as the new animal type
			else
			{
				//if there are no turtles, remove a tiger
				if (turtCount == 0)
				{
					tigerCount -= 1;
					//write status message to file
					outFileObj << "A tiger died today due to sickness. You now have " << tigerCount << " tiger(s).";
				}
				//if there are turtles, remove a turtle
				else
				{
					turtCount -= 1;
					//write status message to file
					outFileObj << "A turtle died today due to sickness. You now have " << turtCount << " turtle(s).";
				}
			}
		}
		//if there are penguins, remove a turtle
		else
		{
			pengCount -= 1;
			//write status message to file
			outFileObj << "A penguin died today due to sickness. You now have " << pengCount << " penguin(s).";
		}
	}
	//if turtle is chosen
	else
	{
		//if there are no turtles
		if (turtCount == 0)
		{
			//select new animal type, between tiger and penguin
			newAnimalType = rand() % 2 + 1;
			//if tiger is selected as the new animal type 
			if (newAnimalType == 1)
			{
				//if there are no tigers, remove a penguin
				if (tigerCount == 0)
				{
					pengCount -= 1;
					//write status message to file
					outFileObj << "A penguin died today due to sickness. You now have " << pengCount << " penguin(s).";
				}
				//if there are tigers, remove a tiger
				else
				{
					tigerCount -= 1;
					//write status message to file
					outFileObj << "A tiger died today due to sickness. You now have " << tigerCount << " tiger(s).";
				}
			}
			//if penguin is selected as the new animal type
			else
			{
				//if there are no penguins, remove a tiger
				if (pengCount == 0)
				{
					tigerCount -= 1;
					//write status message to file
					outFileObj << "A tiger died today due to sickness. You now have " << tigerCount << " tiger(s).";
				}
				//if there are penguins, remove a penguin
				else
				{
					pengCount -= 1;
					//write status message to file
					outFileObj << "A penguin died today due to sickness. You now have " << pengCount << " penguin(s).";
				}
			}
		}
		//if there are turtles, remove a turtle
		else
		{
			turtCount -= 1;
			//write status message to file
			outFileObj << "A turtle died today due to sickness. You now have " << turtCount << " turtle(s).";
		}
	}
	
	//close output file
	outFileObj.close(); 
	//open the same file to read, this time
	readFileObj.open(inItFileName);
	
	//if able to read a line from file, display message
	if (getline(readFileObj, message))
	{
		std::cout << message << std::endl; 
	}
	//if unable to read from file, display error
	else
	{
		std::cout << "Open " << inItFileName << " failed.\n"; 
	}

}

/*********************************************************************
bonusEvent function
** Description: Random event #2. This function accepts three parameters, 
				two being ofstream and ifstream objects and the third 
				being the filename. The ofstream and ifstream objects 
				are for writing and reading from file. 
				This function generates a random bonus for each tiger
				in the zoo. Random bonus is between 250 and 500. 
				If there are no tigers, no bonus is generated and a
				no bonus message is write to file. If there are 
				tigers in the zoo, generate a random bonus and write
				the bonus message to file. 
				After the message is written to file, the file is closed
				and reopened to read the message from file. 
*********************************************************************/
void Zoo::bonusEvent(std::ofstream & outFileObj, std::ifstream & readFileObj, std::string inItFileName)
{
	//variable to store message read from file 
	std::string message;

	//variable to store bonus amount
	int randBonus = 0;

	//if there are no tigers, no bonus
	if (tigerCount == 0)
	{
		//write status message to file
		outFileObj << "Tigers generate more money today! However you have no tigers in the zoo so you do not receive any extra revenue.\n"; 
	}
	else
	{
		//generate a random bonus between 250 and 500
		randBonus = rand() % 251 + 250; 
		//write status message to file
		outFileObj << "Tigers generate more money today! You made: " << randBonus << " extra dollars for each tiger you own!\n"; 
	}

	//save bonus amount
	tigList->setBonus(randBonus); 

	//close output file
	outFileObj.close();
	//open the same file to read, this time
	readFileObj.open(inItFileName);

	//if able to read a line from file, display message
	if (getline(readFileObj, message))
	{
		std::cout << message << std::endl;
	}
	//if unable to read from file, display error message
	else
	{
		std::cout << "Open " << inItFileName << " failed.\n";
	}
}

/*********************************************************************
babyEvent function
** Description: Random event #3. Function stimulates a birthing event
				for the randomly selected animal type. It accepts four 
				parameters, the first two being fstream objects, the 
				third being filename and lastly the selected random 
				animal type. First it tests to see if there are any
				adult animals and if there are any animals. 
				If the randomly selected animal type does not have
				any adults, then another animal type will be selected 
				to have the baby. For the born baby, an addAnimal function
				will be called to add X number of babies and set the
				bab
				A status message will be written and read from file. 
*********************************************************************/
void Zoo::babyEvent(std::ofstream & outFileObj, std::ifstream & readFileObj, std::string inItFileName, int inItAnimalType)
{

	int newAnimalType = 0,	//variable to store another type of animal in case the random animal doesn't exist
		babyAge = 0;		//baby's age, set to 0

	//variable to store message read from file 
	std::string message = " ";

	//checks to see if there are adult animals
	bool adultTiger = tigList->hasAdult(),
		adultPeng = pengList->hasAdult(),
		adultTurt = turtList->hasAdult(); 

	//if there are no animals in the category, there are no adults
	if (tigerCount == 0)
	{
		adultTiger = false;
	}
	else if(pengCount == 0)
	{
		adultPeng = false; 
	}
	else if (turtCount == 0)
	{
		adultTurt = false; 
	}

	//if there are no adult animals, no babies born
	if ((!adultTiger) && (!adultPeng) && (!adultTurt))
	{
		//write status message to file
		outFileObj << "There are no adult animals in the zoo so no babies are born today.\n";
	}

	//if there are adult animals
	else
	{
		//if tiger is chosen to have baby
		if (inItAnimalType == 1)
		{
			//if there are no adult tigers
			if (!adultTiger)
			{
				//select new animal type to have baby, between penguin and turtle
				newAnimalType = rand() % 2 + 1;

				//if penguin is selected as the new animal type
				if (newAnimalType == 1)
				{
					//if there are no adult penguins
					if (!adultPeng)
					{
						//select turtle to have baby
						//add babie turtles and set age to 0
						addTurt(turtList->getBabies(), babyAge);
						//save status message to file
						outFileObj << "10 baby turtles are born today!\n";
					}
					//if there are adult penguins
					else
					{
						//add baby penguins and set age to 0
						addPeng(pengList->getBabies(), babyAge);
						//save status message to file
						outFileObj << "5 baby penguins are born today!\n";
					}
				}
				//if turtle is selected as the new animal type
				else
				{
					//if there are no adult turtles
					if (!adultTurt)
					{
						//select penguin to have baby
						//add baby penguins and set age to 0
						addPeng(pengList->getBabies(), babyAge);
						//save status message to file
						outFileObj << "5 baby penguins are born today!\n";
					}
					//if there are adult turtles
					else
					{
						//select turtle to have baby
						//add babie turtles and set age to 0
						addTurt(turtList->getBabies(), babyAge);
						//save status message to file
						outFileObj << "10 baby turtles are born today!\n";
					}
				}
			}
			//if there are adult tigers
			else
			{
				//add baby tiger and set age to 0
				addTiger(tigList->getBabies(), babyAge);
				//save status message to file
				outFileObj << "1 baby tiger is born today!\n";
			}
		}
		//if penguins are selected to have a baby
		else if (inItAnimalType == 2)
		{
			//if there are no adult penguins
			if (!adultPeng)
			{
				//select new animal type to have baby, between tiger and turtle
				newAnimalType = rand() % 2 + 1;

				//if tiger is selected as the new animal type
				if (newAnimalType == 1)
				{
					//if there are no adut tigers
					if (!adultTiger)
					{
						//select turtle to have baby
						//add babie turtles and set age to 0
						addTurt(turtList->getBabies(), babyAge);
						//save status message to file
						outFileObj << "10 baby turtles are born today!\n";
					}
					//if there are adult tigers
					else
					{
						//add baby tiger and set age to 0
						addTiger(tigList->getBabies(), babyAge);
						//save status message to file
						outFileObj << "1 baby tiger is born today!\n";
					}
				}
				//if turtle is selected to have baby
				else
				{
					//if there are no adult turtles, then tiger will have the baby
					if (!adultTurt)
					{
						//add baby tiger and set age to 0
						addTiger(tigList->getBabies(), babyAge);
						//save status message to file
						outFileObj << "1 baby tiger is born today!\n";
					}
					//if there are adult turtles, turtle will have the baby
					else
					{
						//add babie turtles and set age to 0
						addTurt(turtList->getBabies(), babyAge);
						//save status message to file
						outFileObj << "10 baby turtles are born today!\n";
					}
				}
			}
			//if there are adult penguins
			else
			{
				//add baby penguins and set age to 0
				addPeng(pengList->getBabies(), babyAge);
				//save status message to file
				outFileObj << "5 baby penguins are born today!\n";
			}
		}
		//if turtles are selected to have babies
		else
		{
			//if there are no adult turtles
			if (!adultTurt)
			{
				//select new animal type to have baby, between tiger and penguin
				newAnimalType = rand() % 2 + 1;

				//if tiger is selected as the new animal type 
				if (newAnimalType == 1)
				{
					//if there are no adult tigers
					if (!adultTiger)
					{
						//select penguin to have baby
						//add baby penguins and set age to 0
						addPeng(pengList->getBabies(), babyAge);
						//save status message to file
						outFileObj << "5 baby penguins are born today!\n";
					}
					//if there are adult tigers, select tiger to have baby
					else
					{
						//add baby tiger and set age to 0
						addTiger(tigList->getBabies(), babyAge);
						//save status message to file
						outFileObj << "1 baby tiger is born today!\n";
					}
				}
				//if penguin is selected as the new animal type
				else
				{
					//if there are no adult penguins, tiger will have the baby
					if (!adultPeng)
					{
						//add baby tiger and set age to 0
						addTiger(tigList->getBabies(), babyAge);
						//save status message to file
						outFileObj << "1 baby tiger is born today!\n";
					}
					//if there are adult penguins
					else
					{
						//add baby penguins and set age to 0
						addPeng(pengList->getBabies(), babyAge);
						//save status message to file
						outFileObj << "5 baby penguins are born today!\n";
					}
				}
			}
			//if there are adult turtles, turtle will have the baby
			else
			{
				//add babie turtles and set age to 0
				addTurt(turtList->getBabies(), babyAge);
				//save status message to file
				outFileObj << "10 baby turtles are born today!\n";
			}
		}
	}

	//close output file
	outFileObj.close();
	//open the same file to read, this time
	readFileObj.open(inItFileName);

	//if able to read a line from file, display message
	if (getline(readFileObj, message))
	{
		std::cout << message << std::endl;
	}
	//if unable to read from file, display error message
	else
	{
		std::cout << "Open " << inItFileName << " failed.\n";
	}
}

/*********************************************************************
noEvent function
** Description: Random event #4. This function accepts three parameters, 
				two being ofstream and ifstream objects and the third 
				being the filename. The ofstream and ifstream objects 
				are for writing and reading from file. 
				Function stores a message that describes nothing
				happened in the ofstream object. After the message 
				is written to file, the file is closed and reopened to 
				read the message from file. 
*********************************************************************/
void Zoo::noEvent(std::ofstream & outFileObj, std::ifstream & readFileObj, std::string inItFileName)
{
	//variable to save the message 
	std::string message; 

	//write message to file
	outFileObj << "Nothing happened today.\n"; 

	//close output file
	outFileObj.close();
	//open the same file to read, this time
	readFileObj.open(inItFileName);

	//if able to read a line from file, display message
	if (getline(readFileObj, message))
	{
		std::cout << message << std::endl;
	}
	//if unable to read from file, display error message
	else
	{
		std::cout << "Open " << inItFileName << " failed.\n";
	}
}

/*********************************************************************
startMenu function
** Description: Function to display the start menu. It has three string
				variables that can be altered to display menu option
				messages.
				intro - introductary message
				option1 - start menu option 1 (continue to menu 2)
				exitMsg - start menu exit option (exit program)
				After displaying the intro message, it calls the
				correct2ChoiceInput function that takes two prompts and
				will ask user for an input and validate it. If a valid
				input is entered, the input/choice will be returned to
				this function. Then based on the input/choice, the program
				will either proceed or exit.
*********************************************************************/
void Zoo::startGame()
{
	std::string intro,
		option1,
		exitMsg;

	int choice;

	intro = "Welcome to the Zoo Tycoon game! Extra credit #2 is in place.\n";
	option1 = "1. Play Game";
	exitMsg = "2. Exit Game";

	std::cout << intro;
	choice = correct2ChoiceInput(option1, exitMsg);

	//if user wants to start game
	if (choice == 1)
	{
		//calls function to prompt user to purchase animals
		buyMenu(); 
	}
	//exit game
	else if (choice == 2)
	{
		std::cout << "Bye!\n";
	}
}

/*********************************************************************
buyMenu function
** Description: Function to display buy menu "aka. menu 2" after
				the user chooses to continue from start menu. User
				will be asked for several interger inputs to determine
				the number of animals to purchase.
				The inputs will have a correct1Choice function to
				validate the input.
				After the purchases are made, it will call the gameMenu
				to display each turns' results. 
*********************************************************************/
void Zoo::buyMenu()
{
	std::string intro,		//input prompts
		bankBal, 
		tigerCost,
		penguinCost,
		turtleCost,
		buyTiger,
		buyPenguin,
		buyTurtle; 

	int buyAnimal = 0;		//number of purchased animals

	//define prompts
	intro = "You have a starting balance of $";
	bankBal = "You now have a balance of $"; 
	tigerCost = "Tigers cost $"; 
	penguinCost = "Penguines cost $";
	turtleCost = "Turtles cost $"; 
	buyTiger = "Please select the number of tiger(s) you wish to purchase (1 or 2): ";
	buyPenguin = "Please select the number of penguine(s) you wish to purchase (1 or 2):  ";
	buyTurtle = "Please select the number of turtle(s) you wish to purchase (1 or 2): ";

	//display starting cash balance
	std::cout << intro << cashBal << std::endl;
	//display tiger cost
	std::cout << tigerCost << tigList->getCost() << ".\n"; 
	//prompt user to select 1 or 2 tigers to purchase and validate input
	buyAnimal = correct1ChoiceInput(buyTiger);
	
	//buy 1 tiger
	if (buyAnimal == 1)
	{
		//initialize number of tigers to 1
		tigerCount = 1;
	}
	else
	{
		//initialize number of tigers to 2
		tigerCount = 2;
	}

	//deduct tiger(s) cost from balance
	spendCash(tigList->getCost() * tigerCount); 

	//display new balance cash amount
	std::cout << bankBal << cashBal << ".\n"; 
	//display penguin cost
	std::cout << penguinCost << pengList->getCost() << ".\n";
	//prompt user to select 1 or 2 penguins to purchase and validate input
	buyAnimal = correct1ChoiceInput(buyPenguin);

	//buy 1 penguin
	if (buyAnimal == 1)
	{
		//initialize number of penguins to 1
		pengCount = 1;
	}
	else
	{
		//initialize number of pengiuns to 2
		pengCount = 2;
	}

	//deduct penguin(s) cost from balance
	spendCash(pengList->getCost() * pengCount);

	//display new balance cash amount
	std::cout << bankBal << cashBal << ".\n";
	//display turtle cost
	std::cout << turtleCost << turtList->getCost() << ".\n";
	//prompt user to select 1 or 2 turtles to purchase and validate input
	buyAnimal = correct1ChoiceInput(buyTurtle);

	//buy 1 turtle
	if (buyAnimal == 1)
	{
		//initialize number of turtles to 1
		turtCount = 1;
	}
	else
	{
		//initialize number of turtles to 2
		turtCount = 2;
	}

	//deduct turtle(s) cost from balance
	spendCash(turtList->getCost()*turtCount);

	//display new balance cash amount
	std::cout << bankBal << cashBal << std::endl;

	//call menu to display each day's result
	gameMenu(); 

}

/*********************************************************************
gameMenu function
** Description: Function to each game round's result. It first increases
				the day/round count and animals' age. Then depending on
				whether the player has cash to cover the costs, the
				game will either continue or exit. If the game continues,
				it will call a random event. At the end of the day, it 
				asks the user if they would like to buy an animal and
				whether they would like to continue the game. If yes, 
				it will show a summary of the day. 
*********************************************************************/
void Zoo::gameMenu()
{
	//display prompts
	std::string dayNum = "Day ",
		continuePrompt = "Would you like to continue playing? [Y/N]";

	//if user would like to continue playing
	char continueChoice = ' ';

	//loop control variable
	bool continueGame = true; 

	//if cash balance at the start of the day is zero, display message and end game 
	if (cashBal <= 0)
	{
		std::cout << "You do not have enough money to pay for food. The game has ended.\n";
		continueGame = false;
	}

	//runs game when cash balance is above 0
	while (continueGame)
	{
		//increment day count
		day += 1; 

		//display day # in the beginning of each 'round'
		std::cout << "\n" << dayNum << day << std::endl; 
		std::cout << "_______________________" << std::endl; 
		std::cout << "\n";

		//increase all animals' age and display them
		increaseAge();

		//if there is not enough money for food, end game
		if (getTotalFoodCost() > cashBal)
		{
			std::cout << "You do not have enough money to pay for food. The game has ended.\n";
			continueGame = false; 
		}

		//if there is money left over from paying off food
		else
		{
			//deduct food cost from cash balance
			spendCash(getTotalFoodCost()); 
			//display cashbalance after paying off food
			std::cout << "\nYour cash balance after paying off $" << getTotalFoodCost() << " of food is $" << cashBal << std::endl;
			std::cout << "\n";

			//if there are no animals in the zoo, skip random event 
			if (getTotalAnimal() == 0)
			{
				std::cout << "There are no animals in the zoo so there is no event today.\n"; 
			}
			//if there are animals, generate random event
			else
			{
				genRandEvent(); 
			}

			//display day summary 
			std::cout << "\nSummary of Day " << day << " :\n";
			displayAnimal();
			//count and display total number of animals in zoo
			std::cout << "Total number of animals: " << getTotalAnimal() << std::endl;
			//display income
			std::cout << "Total income: $" << getIncome() << std::endl;
			cashBal += getIncome(); 
			std::cout << "New cash balance: $" << cashBal << std::endl; 
			std::cout << "\n";

			//ask use if they would like to buy an adult animal
			buyAnimal(); 
		}

		//ask user if they would like to continue playing
		continueChoice = correctCharInput(continuePrompt); 

		//if user would like to stop playing, end game
		if (continueChoice == 'N')
		{
			continueGame = false;
			std::cout << "Bye!" << std::endl; 
		}
		else
		{
			//if continue, if user does not have enough money, end game
			if (cashBal <= 0)
			{
				continueGame = false; 
				std::cout << "Sorry you don't have any more money. The game has ended." << std::endl; 
			}
		}
	}

}

/*********************************************************************
buyAnimal function
** Description: Function that prompts the user if they would like to
				purchase an adult animal. The user's char choice is then
				validated by the correctCharInput function. If user
				wants to buy, then increments the animal's count by 1 
				and set the new animal's age to 3. If the user does not
				want to buy, return to gameMenu and no increments take
				place. 
*********************************************************************/
void Zoo::buyAnimal()
{
	//display prompts
	std::string buyPrompt,
		animalPrompt,
		buyTiger,
		buyPeng,
		buyTurt;

	//user's choice to purchase - Y or N
	char buyChoice = ' ';

	//user's choice of animal to purchase
	int aniChoice = 0;

	//define the prompts
	buyPrompt = "Would you like to purchase an adult animal? [Y/N]";
	animalPrompt = "Which animal would you like to purchase?\n";
	buyTiger = "1. Tiger\n";
	buyPeng = "2. Penguin\n";
	buyTurt = "3. Turtle\n";

	//validate user's input on purchase choice
	buyChoice = correctCharInput(buyPrompt);

	//if user wants to puchase another animal
	if (buyChoice == 'Y')
	{
		//display animal options
		std::cout << animalPrompt << std::endl;
		aniChoice = correct3ChoiceInput(buyTiger, buyPeng, buyTurt);

		//if tiger is selected 
		if (aniChoice == 1)
		{
			//if cash balance cannot cover cost of 1 tiger
			if (cashBal < tigList->getCost())
			{
				std::cout << "You do not have enough money to buy a tiger.\n";
			}
			else
			{
				//add 1 tiger to count and set age to 3
				addTiger(1, 3);
				//deduct cost of tiger from balance 
				spendCash(tigList->getCost());
			}
		}
		//if penguin is selected
		else if (aniChoice == 2)
		{
			//if cash balance cannot cover cost of 1 penguin
			if (cashBal < pengList->getCost())
			{
				std::cout << "You do not have enough money to buy a penguin.\n";
			}
			else
			{
				//add 1 penguin to count and set age to 3
				addPeng(1, 3);
				//deduct cost of penguin from balance
				spendCash(pengList->getCost());
			}
		}
		//if turtle is selected
		else if (aniChoice ==3)
		{
			//if cash balance cannot cover cost of 1 turtle
			if (cashBal < turtList->getCost())
			{
				std::cout << "You do not have enough money to buy a turtle.\n";
			}
			else
			{
				//add 1 turtle to count and set age to 3
				addTurt(1, 3);
				//deduct cost of turtle from balance
				spendCash(turtList->getCost());
			}
		}
	}

}

/*********************************************************************
correct1ChoiceInput function
** Description: Numbered choice input validation function. Takes in
				one parameters that contain the prompt. User reads
				the prompt and has to enter the correct integer choice.
				If the user-entered choice is set to be higher than the
				maximum-numbered choice and lower than the minimum-
				numbered choice or enters a decimal number or other
				data types like string or char, the input is invalid.
				User will be prompted to re-enter.
				When the input choice satisfies the above conditions,
				the function returns the input as an integer.
				Referenced https://www.youtube.com/watch?v=m2P5A4nR51g
*********************************************************************/
int Zoo::correct1ChoiceInput(std::string inputPrompt1)
{
	//set to be string to capture all that the user entered
	std::string choice;

	int minChoice = 1,
		maxChoice = 2;

	int numChoice = 0;

	//get user input
	std::cout << inputPrompt1 << std::endl;
	getline(std::cin, choice);

	//input need to be readable, length needs to be 1 and it needs to be either 1 or 2
	while (!std::cin || choice.length() != 1 || (choice[0] != '1' && choice[0] != '2'))
	{
		//clear invalid input
		std::cin.clear();
		//discard invalid input
		std::cin.ignore(256, '\n');
		//prompt user to re-enter input
		std::cout << "The valid choices are " << minChoice << " and " << maxChoice << "." << std::endl;
		std::cout << "Please re-enter your choice." << std::endl;
		getline(std::cin, choice);
	}

	if (choice[0] == '1')
	{
		numChoice = 1;
	}
	else
	{
		numChoice = 2;
	}
	return numChoice;
}

/*********************************************************************
correct2ChoiceInput function
** Description: Numbered choice input validation function. Takes in
				two parameters that contain the prompt. User reads
				the prompt and has to enter the correct integer choice.
				If the user-entered choice is set to be higher than the
				maximum-numbered choice and lower than the minimum-
				numbered choice or enters a decimal number or other
				data types like string or char, the input is invalid.
				User will be prompted to re-enter.
				When the input choice satisfies the above conditions,
				the function returns the input as an integer.
				Referenced https://www.youtube.com/watch?v=m2P5A4nR51g
*********************************************************************/
int Zoo::correct2ChoiceInput(std::string inputPrompt1, std::string inputPrompt2)
{
	//set to be string to capture all that the user entered
	std::string choice;

	int minChoice = 1,
		maxChoice = 2;

	int numChoice = 0;

	//get user input
	std::cout << inputPrompt1 << std::endl;
	std::cout << inputPrompt2 << std::endl;
	getline(std::cin, choice);

	//input need to be readable, length needs to be 1 and it needs to be either 1 or 2
	while (!std::cin || choice.length() != 1 || (choice[0] != '1' && choice[0] != '2'))
	{
		//clear invalid input
		std::cin.clear();
		//discard invalid input
		std::cin.ignore(256, '\n');
		//prompt user to re-enter input
		std::cout << "The valid choices are " << minChoice << " and " << maxChoice << "." << std::endl;
		std::cout << "Please re-enter your choice." << std::endl;
		getline(std::cin, choice);
	}

	if (choice[0] == '1')
	{
		numChoice = 1;
	}
	else
	{
		numChoice = 2;
	}
	return numChoice;
}

/*********************************************************************
correct3ChoiceInput function
** Description: Numbered choice input validation function. Takes in
				three parameters that contain the prompts. User reads
				the prompt and has to enter the correct integer choice.
				If the user-entered choice is set to be higher than the
				maximum-numbered choice and lower than the minimum-
				numbered choice or enters a decimal number or other
				data types like string or char, the input is invalid.
				User will be prompted to re-enter.
				When the input choice satisfies the above conditions,
				the function returns the input as an integer.
				Referenced https://www.youtube.com/watch?v=m2P5A4nR51g
*********************************************************************/
int Zoo::correct3ChoiceInput(std::string inputPrompt1, std::string inputPrompt2, std::string inputPrompt3)
{
	//set to be string to capture all that the user entered
	std::string choice;

	//set min and max numbered choices
	//three prompts means max 3 choices
	int minChoice = 1,
		maxChoice = 3,
		numChoice = 0;

	//get user input
	std::cout << inputPrompt1 << std::endl;
	std::cout << inputPrompt2 << std::endl;
	std::cout << inputPrompt3 << std::endl;
	getline(std::cin, choice);

	//input need to be readable, length needs to be 1 and it needs to be either 1 or 2
	while (!std::cin || choice.length() != 1 || (choice[0] != '1' && choice[0] != '2' && choice[0] != '3'))
	{
		//clear invalid input
		std::cin.clear();
		//discard invalid input
		std::cin.ignore(256, '\n');
		//prompt user to re-enter input
		std::cout << "The valid choices are " << minChoice << " and " << maxChoice << "." << std::endl;
		std::cout << "Please re-enter your choice." << std::endl;
		getline(std::cin, choice);
	}

	//convert first letter to int choice
	if (choice[0] == '1')
	{
		numChoice = 1;
	}
	else if (choice[0] == '2')
	{
		numChoice = 2;
	}
	else 
	{
		numChoice = 3;
	}

	return numChoice;
}

/*********************************************************************
correctCharInput function.
** Description: Input validation function for char input. Takes in
				one parameter that contains the prompt. It uses a while
				loop to validate the input and tests it against other
				data types, such as string or numbers.
				Returns the input when it is valid, stored in char
				variable choice.
				Referenced https://stackoverflow.com/questions/15575799/c-how-to-restrict-input-to-one-char-at-a-time
				Referenced https://www.youtube.com/watch?v=m2P5A4nR51g
*********************************************************************/
char Zoo::correctCharInput(std::string inputPrompt1)
{
	std::string input;
	char choice;
	bool invalidInput = true;    //loop control variable

	//get user input
	std::cout << inputPrompt1 << std::endl;
	std::getline(std::cin, input);

	while (invalidInput)
	{
		//if the input is less/more than 1 character long, invalid
		if (input.length() != 1)
		{
			//clear invalid input
			std::cin.clear();
			//discard invalid input
			std::cin.ignore(256, '\n');
			//prompt user to re-enter input
			std::cout << "Invalid input. Please enter Y/y or N/n: " << std::endl;
			std::getline(std::cin, input);
		}
		//if the input is not A/a or B/b, invalid
		else if ((toupper(input[0]) != 'Y') && (toupper(input[0]) != 'N'))
		{
			//clear invalid input
			std::cin.clear();
			//discard invalid input
			std::cin.ignore(256, '\n');
			//prompt user to re-enter input
			std::cout << "Invalid input. Please enter Y/y or N/n: " << std::endl;
			std::getline(std::cin, input);
		}
		//once it passes both tests, can stop the validation loop
		else
		{
			invalidInput = false;
		}
	}
	//set choice to be the first and only character in the string
	choice = input[0];

	return toupper(choice);
}