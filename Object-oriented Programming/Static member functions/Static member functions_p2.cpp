#include <iostream>

class IDGenerator
{
private:
	static int s_nextID; // Heres the declaration for a static member

public:
	static int getNextID(); // Heres the declaration for a static function
};

int IDGenerator::s_nextID{ 1 }; // start the count at 1

int IDGenerator::getNextID() { return s_nextID++; } // return s_next++

int main()
{
	for (int count{ 0 }; count < 5; ++count)
	{
		std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';
	}

	return 0;
}
//
