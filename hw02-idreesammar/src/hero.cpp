#include "hero.h"
#include "strlib.h"
#include <iostream>

// parameterized constructor
Hero::Hero(const std::string& heroDef)
{
	// split heroDef into a vector holding 1) name 2) power list 3) health
	std::vector<std::string> heroInfo = strSplit(heroDef,'|'); 

	mName = heroInfo[0]; // assign the name into mName
	mHealth = std::stoi(heroInfo[2]); // assign health into mHealth (which starts at max value) as int value
	mMaxHealth = std::stoi(heroInfo[2]); // also assign health into mMaxHealth as int value
	// split content of heroInfo[1] into various powers
	std::vector<std::string> heroPowers = strSplit(heroInfo[1],',');
	// loop through all powers and use power factory to assign them as pointers to mPowers
	for (int i = 0; i < heroPowers.size(); i++) 
	{
		mPowers.push_back(powerFactory(heroPowers[i])); // add each respective power (as a pointer) to mPowers 
	}
}

std::string Hero::getName()
{
	// return the hero's name attribute
	return mName;
}

Power* Hero::useRandomPower()
{
	// use std::rand to generate a random number
	int randomChoice = std::rand() % mPowers.size(); // obtain random value from 0 up to the last index of mPowers

	// display the hero name and power's flavor text to cout
	std::cout << mName << " " << mPowers[randomChoice]->use() << std::endl; 
	return mPowers[randomChoice]; // return that pointer to randomly selected power
}

int Hero::getHealth()
{
	// returns the current health (not max health) of the hero
	return mHealth;
}

void Hero::takeDamage()
{
	// decrement hero's mHealth by 1 pt
	mHealth--;
}

void Hero::resetHealth()
{
	// set Hero's current health (mHealth) to max value
	mHealth = mMaxHealth;
}

std::ostream& operator<<(std::ostream& out, const Hero& h)
{
	out << h.mName << " has the following powers..." << std::endl;
	
	for (int i = 0; i < h.mPowers.size(); i++)
	{
		std::cout << "\t" << *(h.mPowers[i]) << std::endl;
	}

	return out;
}
