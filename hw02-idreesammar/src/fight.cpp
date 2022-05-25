#include "fight.h"

bool loadHeroes(const std::string& fileName, std::vector<Hero*>& heroVector)
{
	// first delete any prexisting data in heroVector
	heroVector.clear();
	
	std::ifstream inputFile(fileName); // open the input stream
	if (inputFile.is_open()) 
	{ // if the input file was successfully opened
		// will continue looping till reaching end of the file
		while (!(inputFile.eof()))	// while the end has not been reached
		{ 
			std::string heroLine; // the current hero in the current line of the file
			std::getline(inputFile, heroLine); // get the current line in the file into heroLine
			Hero* newHero = new Hero(heroLine); // create new hero object 
			heroVector.push_back(newHero); // add the hero pointer to the heroVector
		}
		inputFile.close(); // close the file
	}
	else  // file could not be found or opened
	{  
		std::cout << "Unable to load file \"" << fileName << "\"!" << std::endl;
		return false; // the function failed :(
	}

	return true; // the function succeeded :)
}

Hero* selectHero(std::vector<Hero*>& heroVector, const std::string& prompt, std::ostream& out, std::istream& in)
{
	Hero* selectHero = nullptr; // will hold pointer to the selected hero (currently initilized to nullptr)
	std::string userInput; // the user's input (may not be an number as desired)
	bool validInt = false; // boolean used to see if the user input is valid (e.g. is an int withing range of heroVector)
	
	while (!validInt)	// keep looping while user input is not valid
	{ 
		// display prompt to the output stream
		out << prompt;
		in >> userInput; // obtain user input 
		// check if string is an number
		int counter = 0; //denotes how many chars in the userInput are numbers
		// use loop to check if each char in the userInput string is a number
		for (int i = 0; i < userInput.size(); i++) 
		{
			// iterate over each char using isdigit, boolean for isNum, then use if statement)
			if (isdigit(userInput[i])) { // isdigit checks to see if the char is a digit
				counter++;
			}
		}
		if (counter == userInput.size()) 
		{ // userInput was a number (no other chars)
			int userInt = std::stoi(userInput); // convert the string input to an integer
			// now check to see if the userInt is in the valid range of heroVector
			if ((userInt >= 0) && (userInt <= heroVector.size()-1)) 
			{
				validInt = true; // the boolean is now set to true (can leave while loop)
				selectHero = heroVector[userInt]; // set pointer to the hero at users' index choice
			}
		}
	}
	return selectHero; // return the selected hero pointer

}

void heroCombat(Hero* heroA, Hero* heroB, std::ostream& output)
{
	// first reset both hero's health to max before the fight
	heroA->resetHealth();
	heroB->resetHealth();

	// pointers to each hero's random power (will get set to something new each round - currently nullptr)
	Power* heroAPower = nullptr;
	Power* heroBPower = nullptr;

	// loop throught the battle stages until one (or both) hero's health points become 0
	while (!((heroA->getHealth() == 0) || (heroB->getHealth() == 0))) 
	{
		output << "---------------------------------------" << std::endl; // the divider beginning each round
		// dislpay current health points of each hero
		output << heroA->getName() << " has " << heroA->getHealth() << " health" << std::endl;
		output << heroB->getName() << " has " << heroB->getHealth() << " health" << std::endl;
		// have both hero's select and use a random power and store each random power pointer
		heroAPower = heroA->useRandomPower();
		heroBPower = heroB->useRandomPower();
		// assess which power won and which hero took damage this round
		int roundResult = heroAPower->fight(heroBPower);
		if (roundResult == -1)  // heroA lost, heroB won
		{ 
			heroA->takeDamage(); // hero A loses one health point
		}
		else if (roundResult == 1)  // heroA won, heroB lost
		{ 
			heroB->takeDamage();
		}
		else	// roundResult == 0 so both heros tied, (both take damage)
		{ 
			heroA->takeDamage();
			heroB->takeDamage();
		}
	}
	// battle is over, declare the outcome
	output << "---------------------------------------" << std::endl; // the divider before the results
	if ((heroA->getHealth() == 0) && (heroB->getHealth() == 0))   // TIE GAME
	{ 
		output << heroA->getName() << " and " << heroB->getName() << " LOSE!!!" << std::endl;
	}
	else if (heroA->getHealth() == 0)	// only heroA is out of health (heroB won)
	{ 
		output << heroB->getName() << " WINS!!!" << std::endl;
	}
	else if (heroB->getHealth() == 0)	// only heroB is out of health (heroA won)
	{ 
		output << heroA->getName() << " WINS!!!" << std::endl;
	}
	
}

// overloaded fight function
int fight(const std::string& inputFileName, const std::string& outputFileName, unsigned seed)
{
	// open the input and output files
	std::ifstream inputFile(inputFileName);
	std::ofstream outputFile(outputFileName);
	
	if (inputFile.is_open() && outputFile.is_open())	// both files successfully found/opened
	{ 
		// call other fight function
		fight(inputFile, outputFile, seed);
		// close the files streams
		inputFile.close();  
		outputFile.close();
	}
	else	// file could not be found or opened
	{
		std::cout << "Unable to load files" << std::endl;
		return -1; // function failed :(
	}
	return 0; // function was success :)
}

int fight(std::istream& input, std::ostream& output, unsigned seed)
{
	// display the seed and seed the random number generator
	output << "Seed: " << seed << std::endl << std::endl; // display given seed
	std::srand(seed); // use and set the given seed

	char userInput = '5'; // will hold user input (not necessarily an integer) - initialized to char 5
	std::vector<Hero*> heroVector; // will hold heroes loaded (currently empty)
	// for the two hero picks the users will eventually make (initialized to nullptr for now)
	Hero* firstHero = nullptr;
	Hero* secondHero = nullptr;

	// loop until choice 4 is selected to quit
	while (!(userInput=='4')) 
	{
		// display menu for the user to interact with
		output << "Choose an option:" << std::endl << "1. Load Heroes" << std::endl;
		output << "2. Print Hero Roster" << std::endl << "3. Hero Fight!" << std::endl;
		output << "4. Quit" << std::endl << "> ";
		// obtain the user's input
		input >> userInput;
		output << std::endl; // newline

		// use switch statment for different numeric option of menu
		switch (userInput) {
		case '1': // LOAD HEROES 
		{
			output << "Enter the file to load: "; // ask user for name of file to load
			std::string fileName; // to hold the string input with file name
			input.ignore(); // need this for getline to work properly
			std::getline(input, fileName); // obtain input
			loadHeroes(fileName, heroVector); // use loadHeroes function
			break;
		}
		case '2': // LIST HEROES
			// if heroVector is currently empty
			if (heroVector.size() == 0) 
			{
				output << "You need to load some heroes first." << std::endl;
			}
			// heroVector is not empty
			else 
			{
				// denote how many heroes about to be listed
				output << "The following " << heroVector.size() << " heroes are loaded..." << std::endl;
				// loop through each hero in heroVector and display each of their powers
				for (int i = 0; i < heroVector.size(); i++) 
				{
					output << "---------------------------------------" << std::endl; // divider for each entry
					operator<<(output, *(heroVector[i])); // use operator<< friend function in hero.cpp to display powers of hero
				}
				output << "---------------------------------------" << std::endl; // one last divider at end
			}
			break;
		case '3': // HERO FIGHT
			// if heroVector is currently empty
			if (heroVector.size() == 0) 
			{ 
				output << "You need to load some heroes first." << std::endl;
			}
			// heroVector is not empty
			else 
			{
				// first display all heroes and their indicies from heroVector
				for (int i = 0; i < heroVector.size(); i++) 
				{
					output << i << ": " << heroVector[i]->getName() << std::endl;
				}
				// ask and obtain pointer to first hero choice
				firstHero = selectHero(heroVector, "Select your first hero: ", output, input);
				// ask and obtain pointer to second hero choice
				secondHero = selectHero(heroVector, "Select your second hero: ", output, input);
				// have the 2 heroes fight using the heroCombat function
				heroCombat(firstHero, secondHero, output);
			}
			break;
		case '4': // QUIT
			output << "Goodbye" << std::endl; // farewell message
			break;
		default: // for any other char that will cause an error message
			output << "Error: Your input was invalid. Choose between 1-4. Try again." << std::endl;
			break;
		}
		output << std::endl; // newline
	}
	return 0;
}
