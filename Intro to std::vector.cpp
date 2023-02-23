// 2/23/2023 // Introduction to std::vector - Better choice over dynamic arrays since it prevents memory leaks
#include <iostream>
#include <vector> // to use std::vector

// no need to specify length at the dcaration
std::vector<int> v1; 
std::vector<int> v2 = { 9,7,5,3,1 };
std::vector<int> v3{ 9,7,5,3,10 }; //my preference
std::vector v4{ 8,9,6,4,11 }; //c++17 since, we can omit the data type 

void printLength(const std::vector<int>& v)
{
	std::cout << "The vector Length is: " << v.size() << '\n';
}

int main()
{
	v1 = { 10,20,30,40,50 }; //set the data for v1
	
	std::cout << v1.at(0) << '\n';
	std::cout << v1[1] << '\n';

	v1.at(0) = 3; // does bounds checking to make sure the member is in the array
	v1[1] = 7; // doesnt do bounds checking but its faster

	std::cout << v1.at(0) << '\n';
	std::cout << v1[1] << '\n';

	//---------------------------------------------------------------------

	//std::vector helps with preventing memory leaks, once it goes out of scope it releases the memory automatically

	std::vector<int> v5{ 90,70,50,30,10 }; //vectors keep track of their length, we can ask it with 'v.size()'
	printLength(v5); //ex. 1

	std::vector<int> empty{};
	printLength(empty); //ex. 2

	std::cout << '\n';
	//---------------------------------------------------------------------

	std::vector<int> v6{ 11,22,33 }; //member size is 3
	std::cout << "The v6 length before change is: " << v6.size() << '\n';

	for (int member : v6)
	{
		std::cout << member << ' ';
	}

	std::cout << '\n' << '\n';
	v6.resize(5); //sets members size to 5

	std::cout << "The v6 length after is: " << v6.size() << '\n';

	for (int member : v6)
	{
		std::cout << member << ' ';
	}

	std::cout << '\n' << '\n';
	v6.resize(2); //removes the rest of the members and keeps the first 2

	std::cout << "The v6 length after is: " << v6.size() << '\n';
	for (int member : v6)
	{
		std::cout << member << ' ';
	}

	std::cout << '\n' << '\n';
	//---------------------------------------------------------------------

	std::vector<int> v7(5); // Initialization of vector with 5 members
	std::cout << "The v7 length is: " << v7.size() << '\n';

	for (int member : v7)
	{
		std::cout << member << ' ';
	}

	std::cout << '\n' << '\n';
	//---------------------------------------------------------------------

	//std::vector a{ 1, 2, 3 }; allocate 3 elements with values 1, 2, and 3
	//std::vector b{ 3 }; allocate 1 element with value 3
	//std::vector<int> c(3);  allocate 3 elements with values 0, 0, and 0
	//std::vector<int> d(3, 4); allocate 3 elements with values 4, 4, and 4

	//---------------------------------------------------------------------

	//We can also compact bools in arrays... sneaky tech
	std::vector<bool> vBool{ true, false, false, true, true };
	std::cout << "The vBool length is: " << vBool.size() << '\n';

	for (int member : vBool)
	{
		std::cout << member << ' ';
	}

	std::cout << '\n';

	return 0;
}
