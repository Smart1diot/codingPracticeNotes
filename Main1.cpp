#include <iostream>
#include <string_view> //c++17 
#include <string> 

// Define our different monster types as an enum
enum class MonsterType
{
	ogre,
	dragon,
	orc,
	giant_spider,
	slime,
};

// Our monster struct represents a single monster
struct Monster
{
	MonsterType type{};
	std::string stringName{};
	int health{};
};

// Return the name of the monsters type as a string
// Since this can be used elsewhere, its better to make this its own function
constexpr std::string_view getMonsterTypeString(MonsterType type)
{
	switch (type)
	{
	case MonsterType::ogre: return "Ogre";
	case MonsterType::dragon: return "Dragon";
	case MonsterType::orc: return "Orc";
	case MonsterType::giant_spider: return "Giant Spider";
	case MonsterType::slime: return "Slime";
	default: "Unknown";

	}
}

// Print our monsters stats
void printMonster(const Monster& monster) // Function that just prints the details for the object monsters info
{
	std::cout << "This " << getMonsterTypeString(monster.type) <<
		" is named" << monster.stringName <<
		" and has " << monster.health << '\n';
}

int main()
{
	Monster ogre{ MonsterType::ogre, "Shrek", 145 }; // Creating a monster object named ogre with these parameters for its members
	Monster giantSpider{ MonsterType::giant_spider, "Quelaag", 500 }; // Creating a monster obkect named giantSpider with these parameters for its members

	printMonster(ogre); // Function printMonster gets called with ogre
	printMonster(giantSpider); // Function printMonster gets called with giantSpider

	return 0;
}