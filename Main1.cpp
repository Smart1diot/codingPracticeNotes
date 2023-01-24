#include <iostream>


struct Penis //Defining object Penis
{
	int balls{};
	int cock{};
};

const void shit(int number, int& ptr)				// Function that compares two data types, first through regular value copy, the other through weird pointer system 
{													// that I came up with. Only method Ive come across on my own to be able to use struct members in a function.
	if (number == ptr)
		std::cout << "Success!" << '\n';
	else
		std::cout << "Fuck!" << '\n';
}

int main()
{
	Penis p1{ 20,30 };					// Defining object p1

	Penis* ptr{ &p1 };					//Defining pointer for p1

	int randomNumber{ 20 };				//Defining randomNumber{50};

	std::cout << ptr->balls << '\n';	// printing out the number under the struct member, int balls{};

	shit(randomNumber, ptr->balls);		// Lastly function shit() gets called with two variables, the int and Penis: ptr->balls.


	return 0;
}