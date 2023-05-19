#include <iostream>
#include <string>
#include <string_view>
#include <array>

#include "Random.h"

class Monster
{
public:
	enum class Type
	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,

		max_monster_types
	};

private:
	Type m_monsterType{};
	std::string m_name{};
	std::string m_roar{};
	int m_hitPoints{};

public:
	Monster(Type monsterType, std::string_view name, std::string_view roar, int hitPoints)
		: m_monsterType{ monsterType }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints } {}

	std::string getTypeString()
	{
		switch (m_monsterType)
		{
		case Type::dragon:	return "dragon";
		case Type::goblin:	return "goblin";
		case Type::ogre:	return "ogre";
		case Type::orc:		return "orc";
		case Type::skeleton:return "skeleton";
		case Type::troll:	return "troll";
		case Type::vampire:	return "vampire";
		case Type::zombie:	return "zombie";
		default:			return "error no monster selected";
		}
	}

	void print()
	{
		std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
	}
};

namespace MonsterGenerator
{
	Monster generateMonster()
	{
		Monster::Type monster{Random::get(0, 7)};

		int randomHitPoint{ Random::get(1,100) };

		static std::array<std::string, static_cast<int>(Monster::Type::max_monster_types)> s_names{"Drogen","Goblenathan","shrek","orcat","skelly","redditor","marceline","zombitch"};

		static std::array<std::string, static_cast<int>(Monster::Type::max_monster_types)> s_roars{"Drooo","Gobloo","RoaR","orcGrowel","rattle","umm akualy", "hey fin", "brraiinss"};

		std::string monsterName{s_names[static_cast<int>(monster)]};

		std::string monsterRoar{s_roars[static_cast<int>(monster)]};

		return Monster{monster, monsterName, monsterRoar, randomHitPoint};
	}
}

int main()
{
	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}