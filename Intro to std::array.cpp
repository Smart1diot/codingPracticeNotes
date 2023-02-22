//2/22/2023 introduction to std::array
#include <iostream>
#include <array> //must inlude to inlclude and use std::array
#include <algorithm> // to use sort
#include <cstddef> // std::size_t

//just like native implementation of fixed arrays, the length of the std::aray must be know at compile time
std::array<int, 5> myArray1{9,7,5,3,1}; //can assign values in list initialization

std::array<int, 3> myArray2; //can establish array with specific number of members

void printLengthDouble(const std::array<double, 5>& array) // toss a mf array in that bitch, const reference '&' to prevent making copy of array
{
	std::cout << "length: " << array.size() << '\n';

	for (double member : array) //fun shit
	{
		std::cout << member << ' ';
	}
}

template <typename T, std::size_t size> // Template to be able to take any data type as well as any size
void printLengthInt(const std::array<T, size>& array) //this time we pass the array of <T type, and size_t>'&' *Dont forget to reference!*
{
	std::cout << "Length of array: " << array.size() << '\n';

	for (int member : array)
	{
		std::cout << member << ' ';
	}

	std::cout << '\n';

	for (std::size_t i{0}; i < array.size(); ++i) //std::size_t a for loop
	{
		std::cout << array[i] << ' ';
	}
}

struct House
{
	int number{};
	int stories{};
	int roomsPerStory{};
};

int main()
{
	myArray2 = { 11,22,33 }; //before program runs, establish all member's values

	std::array<int, 4> myArray3;
	myArray3.at(1) = 10; 
	myArray3.at(2) = 5;
	myArray3.at(3) = 15;

	std::cout << myArray1[1] << ' ' << myArray2[2] << ' ' << myArray3[1] << '\n'; //prints out '7', '33', and '10' i like this method better tbh
	std::cout << myArray1.at(2) << ' ' << myArray2.at(1) << ' ' << myArray3.at(2) << '\n'; //prints out '5', '22', and '9' just like the one above pretty much.

	std::array<double, 5> myArray4{ 9.0,7.2,5.4,3.6,1.8 }; // i change my mind this is my favorite array access so far
	printLengthDouble(myArray4);
	std::cout << '\n';

	std::array<int, 10> myArray5{ 13,59,45,7,36,43,8,10,69,99 }; // *ABSOLUTE* favorite woah!
	std::sort(myArray5.begin(), myArray5.end());
	printLengthInt(myArray5);
	std::cout << '\n' << '\n';

	//-------------------------------------------------------------------------------

	std::array<House, 3> house //using structs with std::arrays, badass!
	{
		{
			{13,4,30},
			{14,3,10}, //requires an extra set of curly brackets when using structs
			{15,3,40},
		}
	};

	//try using std::array over built-in fixed arrays for any non-trivial array use


	return 0;
}
