#include "powers.h"

#include <iostream>

POWER_ID Power::getID()
{
	// return the power's mPowerID variable
	return mPowerID;
}

/********************************
CODE FOR EACH POWER GOES HERE
*********************************/

// for StrengthPower

	// constructor
	StrengthPower::StrengthPower() 
	{
		mDescription = "Displays impressive physical abilities";
		mPowerID = POWER_STRENGTH;
	}
	// use
	std::string StrengthPower::use() 
	{
		return "SMASH ATTACK!";
	}
	// fight
	int StrengthPower::fight(Power* other) 
	{
		int resultPoint = 0; // indicate 0 if tie, -1 if hero lost, 1 if hero won
		// against FLIGHT
		if (other->getID() == POWER_FLIGHT) 
		{
			std::cout << "FLIGHT WINS - flying away from the attack's range." << std::endl;
			resultPoint = -1;
		}
		// against GADGETS
		if (other->getID() == POWER_GADGETS) 
		{
			std::cout << "STRENGTH WINS - The gadgets are smashed by the attack." << std::endl;
			resultPoint = 1;
		}
		// against INTELLIGENCE
		if (other->getID() == POWER_INTEL) 
		{
			std::cout << "INTELLIGENCE WINS - they outwit and dodge the attack." << std::endl;
			resultPoint = -1;
		}
		// against LASERS
		if (other->getID() == POWER_LASER) 
		{
			std::cout << "STRENGTH WINS - laser beams are no match for those fists." << std::endl;
			resultPoint = 1;
		}
		// against NATIONALISM
		if (other->getID() == POWER_NATIONAL) 
		{
			std::cout << "STRENGTH WINS - that patriotic spirit is no match for those fists." << std::endl;
			resultPoint = 1;
		}
		// against STRENGTH
		if (other->getID() == POWER_STRENGTH) 
		{
			std::cout << "TIE - the impact of the attacks cancelled one another out." << std::endl;
			// resultpoint remains 0
		}
		return resultPoint;
	}
// for NationalPower

	// constructor
	NationalPower::NationalPower() 
	{
		mDescription = "Fights and breathes for the motherland.";
		mPowerID = POWER_NATIONAL;
	}
	// use
	std::string NationalPower::use() 
	{
		return "Screams the national anthem!";
	}
	// fight
	int NationalPower::fight(Power* other) 
	{
		int resultPoint = 0; // indicate 0 if tie, -1 if hero lost, 1 if hero won
		// against FLIGHT
		if (other->getID() == POWER_FLIGHT) 
		{
			std::cout << "FLIGHT WINS - flying away from nationalist propaganda." << std::endl;
			resultPoint = -1;
		}
		// against GADGETS
		if (other->getID() == POWER_GADGETS) 
		{
			std::cout << "GADGETS WINS - The gadgets override the nationalism." << std::endl;
			resultPoint = -1;
		}
		// against INTELLIGENCE
		if (other->getID() == POWER_INTEL) 
		{
			std::cout << "INTELLIGENCE WINS - they outwit and avoid the enemy's patriotism." << std::endl;
			resultPoint = -1;
		}
		// against LASERS
		if (other->getID() == POWER_LASER) 
		{
			std::cout << "LASERS WINS - laser beams shoot and burn the patriot." << std::endl;
			resultPoint = -1;
		}
		// against NATIONALISM
		if (other->getID() == POWER_NATIONAL) 
		{
			std::cout << "TIE - the nationalist screams block one another out." << std::endl;
			// resultPoint remains 0
		}
		// against STRENGTH
		if (other->getID() == POWER_STRENGTH) 
		{
			std::cout << "STRENGTH WINS - the nationalist gets hits hard." << std::endl;
			resultPoint = -1;
		}
		return resultPoint;
	}
// for LaserPower

	// constructor
	LaserPower::LaserPower() 
	{
		mDescription = "Shoots beams at opponents";
		mPowerID = POWER_LASER;
	}
	// use
	std::string LaserPower::use() 
	{
		return "BEAMS FIRE! PEW PEW!";
	}
	// fight
	int LaserPower::fight(Power* other) 
	{
		int resultPoint = 0; // indicate 0 if tie, -1 if hero lost, 1 if hero won
		// against FLIGHT
		if (other->getID() == POWER_FLIGHT) 
		{
			std::cout << "LASERS WINS - shoots the opponent right out of the sky." << std::endl;
			resultPoint = 1;
		}
		// against GADGETS
		if (other->getID() == POWER_GADGETS) 
		{
			std::cout << "GADGETS WINS - crafty tech neutralizes the laser beams." << std::endl;
			resultPoint = -1;
		}
		// against INTELLIGENCE
		if (other->getID() == POWER_INTEL) 
		{
			std::cout << "LASERS WINS - shoot the opponent before they have time to think." << std::endl;
			resultPoint = 1;
		}
		// against LASERS
		if (other->getID() == POWER_LASER) 
		{
			std::cout << "TIE - laser beams collide, cancelling one another." << std::endl;
			// resultPoint remains 0
		}
		// against NATIONALISM
		if (other->getID() == POWER_NATIONAL) 
		{
			std::cout << "LASERS WINS - that patriotic spirit is no match for those laser beams." << std::endl;
			resultPoint = 1;
		}
		// against STRENGTH
		if (other->getID() == POWER_STRENGTH) 
		{
			std::cout << "STRENGTH WINS - the fists smash their way through the lasers." << std::endl;
			resultPoint = -1;
		}
		return resultPoint;
	}
// for IntelligencePower

	// constructor
	IntelPower::IntelPower() 
	{
		mDescription = "Uses their brain to come up with complex strategies.";
		mPowerID = POWER_INTEL;
	}
	// use
	std::string IntelPower::use() 
	{
		return "Strategizes and enacts a plan.";
	}
	// fight
	int IntelPower::fight(Power* other) 
	{
		int resultPoint = 0; // indicate 0 if tie, -1 if hero lost, 1 if hero won
		// against FLIGHT
		if (other->getID() == POWER_FLIGHT) 
		{
			std::cout << "FLIGHT WINS - flying away from the genius's plan." << std::endl;
			resultPoint = -1;
		}
		// against GADGETS
		if (other->getID() == POWER_GADGETS) 
		{
			std::cout << "INTELLIGENCE WINS - dismantles and evades those silly gadgets." << std::endl;
			resultPoint = 1;
		}
		// against INTELLIGENCE
		if (other->getID() == POWER_INTEL) 
		{
			std::cout << "TIE - two complex plans clash and lead to no damage." << std::endl;
			// resultPoint remains 0
		}
		// against LASERS
		if (other->getID() == POWER_LASER) 
		{
			std::cout << "LASERS WINS - laser beams fire and prevent the strategist from thinking." << std::endl;
			resultPoint = -1;
		}
		// against NATIONALISM
		if (other->getID() == POWER_NATIONAL) 
		{
			std::cout << "INTELLIGENCE WINS - distracts and defeats the nationalist using false propaganda." << std::endl;
			resultPoint = 1;
		}
		// against STRENGTH
		if (other->getID() == POWER_STRENGTH) 
		{
			std::cout << "INTELLIGENCE WINS - classic case of brains besting brawns." << std::endl;
			resultPoint = 1;
		}
		return resultPoint;
	}
// for GadgetPower

	// constructor
	GadgetPower::GadgetPower() 
	{
		mDescription = "Utilizes a variety of tech to take on enemies.";
		mPowerID = POWER_GADGETS;
	}
	// use
	std::string GadgetPower::use() 
	{
		return "BEEP! BOOP! GADGETS ACTIVATE!";
	}
	// fight
	int GadgetPower::fight(Power* other) 
	{
		int resultPoint = 0; // indicate 0 if tie, -1 if hero lost, 1 if hero won
		// against FLIGHT
		if (other->getID() == POWER_FLIGHT) 
		{
			std::cout << "GADGETS WINS - the device captures the flying opponent." << std::endl;
			resultPoint = 1;
		}
		// against GADGETS
		if (other->getID() == POWER_GADGETS) 
		{
			std::cout << "TIE - Tech collide, both get hit." << std::endl;
			// resultPoint remains 0
		}
		// against INTELLIGENCE
		if (other->getID() == POWER_INTEL) 
		{
			std::cout << "INTELLIGENCE WINS - big brain power dismantles those silly gadgets." << std::endl;
			resultPoint = -1;
		}
		// against LASERS
		if (other->getID() == POWER_LASER) 
		{
			std::cout << "GADGETS WINS - fancy tech makes the laser beams useless." << std::endl;
			resultPoint = 1;
		}
		// against NATIONALISM
		if (other->getID() == POWER_NATIONAL) 
		{
			std::cout << "GADGETS WINS - patriotism is no match for technology." << std::endl;
			resultPoint = 1;
		}
		// against STRENGTH
		if (other->getID() == POWER_STRENGTH) 
		{
			std::cout << "STRENGTH WINS - smashes the gadgets into tiny little pieces." << std::endl;
			resultPoint = -1;
		}
		return resultPoint;
	}
// for FlightPower

	// constructor
	FlightPower::FlightPower() 
	{
		mDescription = "Has the ability to soar through the skies.";
		mPowerID = POWER_FLIGHT;
	}
	// use
	std::string FlightPower::use() 
	{
		return "*rises into the sky*";
	}
	// fight
	int FlightPower::fight(Power* other) 
	{
		int resultPoint = 0; // indicate 0 if tie, -1 if hero lost, 1 if hero won
		// against FLIGHT
		if (other->getID() == POWER_FLIGHT) 
		{
			std::cout << "TIE - both damage each other in the sky." << std::endl;
			// resultPoint remains 0
		}
		// against GADGETS
		if (other->getID() == POWER_GADGETS) 
		{
			std::cout << "GADGETS WINS - The gadgets capture the flying foe." << std::endl;
			resultPoint = -1;
		}
		// against INTELLIGENCE
		if (other->getID() == POWER_INTEL) 
		{
			std::cout << "FLIGHT WINS - flies out of range of the opponent's plans." << std::endl;
			resultPoint = 1;
		}
		// against LASERS
		if (other->getID() == POWER_LASER) 
		{
			std::cout << "LASERS WINS - laser beams shoot the opponent out of the sky." << std::endl;
			resultPoint = -1;
		}
		// against NATIONALISM
		if (other->getID() == POWER_NATIONAL) 
		{
			std::cout << "FLIGHT WINS - flies away from that patriotic rant." << std::endl;
			resultPoint = 1;
		}
		// against STRENGTH
		if (other->getID() == POWER_STRENGTH) 
		{
			std::cout << "FLIGHT WINS - flies out of range from the opponent's attack." << std::endl;
			resultPoint = 1;
		}
		return resultPoint;
	}

Power* powerFactory(const std::string& powerName)
{
	Power* newPower = nullptr; // pointer to a new power that will be stored on heap

	if (powerName == "strength") 
	{
		newPower = new StrengthPower(); // points to a Strength on heap
	}
	if (powerName == "flight") 
	{
		newPower = new FlightPower(); // points to a Flight on heap
	}
	if (powerName == "laser") 
	{
		newPower = new LaserPower(); // points to a Laser on heap
	}
	if (powerName == "intel") 
	{
		newPower = new IntelPower(); // points to a Intelligence on heap
	}
	if (powerName == "gadget") 
	{
		newPower = new GadgetPower(); // points to a Gadget on heap
	}
	if (powerName == "national") 
	{
		newPower = new NationalPower(); // points to a National on heap
	}
	return newPower; // return the pointer after its been appropriately pointed to a power on the heap
}

std::ostream& operator<<(std::ostream& out, const Power& p)
{
	out << p.mDescription;
	return out;
}
