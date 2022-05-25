#pragma once
#include <string>
#include <vector>
#include <ostream>

#include "powers.h"

class Hero
{
public:
    // Name:
    //        Hero parameterized constructor
    // Input:
    //        1. A string (passed as constant reference) with 3 fields.
    //              a. The hero name followed by a vertical bar "|"
    //              b. A list of comma separated power names
    //              c. The maximum health for that hero
    // Output:
    //        None (it's a constructor)
    // Side effects:
    //        Dynamically creates new powers and puts their memory addresses in the Power vector
    // Summary:
    //        Calls the hero constructor to make all the heros
	Hero(const std::string& heroDef);

    // Name:
    //        getName
    // Input:
    //        None
    // Output:
    //        A std::string with the hero's name
    // Side effects:
    //        None
    // Summary:
    //        Name getter
	std::string getName();
    
    // Name:
    //        useRandomPower
    // Input:
    //        None
    // Output:
    //        A pointer to a random Power as determined by std::rand
    // Side effects:
    //        Displays that power's flavor text
    // Summary:
    //        Name getter
	Power* useRandomPower();

    // Name:
    //        getHealth
    // Input:
    //        None
    // Output:
    //        An int with the hero's current health
    // Side effects:
    //        None
    // Summary:
    //        health getter (Returns the current health of the hero)
	int getHealth();

    // Name:
    //        takeDamage
    // Input:
    //        None
    // Output:
    //        None
    // Side effects:
    //        None
    // Summary:
    //        Causes the hero to take one point of damage
	void takeDamage();

    // Name:
    //        resetHealth
    // Input:
    //        None
    // Output:
    //        None
    // Side effects:
    //        None
    // Summary:
    //        Resets the heroes' health to the max value
	void resetHealth();

	friend std::ostream& operator<<(std::ostream& out, const Hero& h);

private:
	// Max health
	int mMaxHealth;
	// Current health
	int mHealth;
	// Name of hero
	std::string mName;
	// Array of pointers to powers
	std::vector<Power*> mPowers;
};
