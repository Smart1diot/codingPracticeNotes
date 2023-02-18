// 2/17/2023 Allocating Space for 5 user submited strings, then prints them after sorting
#include <iostream>
#include <string>
#include <utility>

int main()
{
	std::cout << "Enter the number of names you wish to enter: ";
	int numOfNames{};
	std::cin >> numOfNames;

	std::string* nameArray{ new std::string[numOfNames]{} }; //we just created an array with a num we decided with
	std::cout << "Enter " << numOfNames << " names below..." << '\n' << '\n';
	
	for (int member{ 0 }; member < numOfNames; ++member)
	{
		std::cin >> nameArray[member];
	}

	std::cout << '\n';

	// I will sort the names before printing now
	for (int iteration{ 0 }; iteration < numOfNames - 1; ++iteration)
	{
		for (int innerIteration{ iteration + 1 }; innerIteration < numOfNames - 1; ++innerIteration)
		{
			if (nameArray[iteration] > nameArray[innerIteration])
			{
				std::swap(nameArray[iteration], nameArray[innerIteration]);
			}
		}
	}

	std::cout << '\n';

	for (int i{ 0 }; i < numOfNames; ++i) //prints out tha order of names
	{
		std::cout << nameArray[i] << '\n';
	}
	

	return 0;
}