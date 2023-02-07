//2/7/23 C-Styled strings some old school method

#include <iostream>
#include <iterator> //to use std::size

int main()
{
	char myString[]{"string"};
	const int length{ static_cast<int>(std::size(myString)) };

	std::cout << myString << " has " << length << " characters.\n";

	for (int index{ 0 }; index < length; ++index)
	{
		std::cout << static_cast<int>(myString[index]) << ' ';
	}

	std::cout << '\n';

	char myString2[]{"string"};
	myString[1] = 'p';
	std::cout << myString << '\n';

	char name[20]{ "Alex" }; //only use 5 characters(4 + 1 null terminator)
	std::cout << name << '\n';

	char name2[255]{}; //declare array large enough to hold 254 characters + null terminator
	std::cout << "Enter Your Name: ";
	std::cin.getline(name2, std::size(name));
	std::cout << "You Entered: " << name << '\n';
	//This call to cin.getline() will read up to 254 characters into name,
	//any excess characters will be discarded, this way no array overflow





	return 0;
}