// 2/19/2023 for-each loops 
#include <iostream>
#include <vector>


int main()
{
	constexpr int fibonacci[]{ 0,1,1,2,3,5,8,13,21,34,55,89 };
	for (int number : fibonacci) //iterate over array fibonacci
	{
		std::cout << number << ' '; //we access the array element for this iteration through variable number
	}

	std::cout << '\n' << '\n';
	
	//for-each loops and the auto keyword
	//using same fibonacci array from ealier
	for (auto number : fibonacci) //type is auto, so number has its type deduced from the fibonacci array
	{
		std::cout << number << ' ';
	}

	std::cout << '\n' << '\n';

	// *Best* read only, for-each element declarations, if your elements are non-fundamental types,
	// use reference or const references for performance reasons
	std::string array[]{ "Peter", "likes", "frozen", "yogurt" };
	for (const auto& element : array)
	{
		std::cout << element << ' ';
	}

	std::cout << '\n' << '\n';

	// Max Score tracker example using for-each loop
	constexpr int scores[]{ 84,92,76,81,56 };
	int maxScore{ 0 };

	for (auto score : scores)
	{
		if (score > maxScore)
		{
			maxScore = score;
		}
	}

	std::cout << "The best score was: " << maxScore << '\n';

	std::cout << '\n' << '\n';

	// for-each loops work with any list-like structures such as vectors, linked lists, trees, maps
	std::vector fibonacci1{ 0,1,1,2,3,5,8,13,21,34,55,89 };

	for (auto number : fibonacci1)
	{
		std::cout << number << ' ';
	}

	std::cout << '\n' << '\n';
	//* for-each doesnt work with pointers to an array, so i cant toss an array into a function because it defaults to a pointer.
	//* In conclusion for-each loops provide a superior syntax for iterating through an array when we need to access all of the array elements in forwards sequential order



	return 0;
}