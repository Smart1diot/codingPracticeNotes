// 2/17/2023 Dynamically Allocating Arrays
#include <iostream>

int main()
{
	std::cout << "Enter a positive integer: ";
	int length{};
	std::cin >> length;

	int* array{ new int[length] {} }; // we use length to determine the num of members that will be in int array as program is running 

	std::cout << "I just allocated an array of integers of length " << length << '\n';

	array[0] = 5; //set element 0 to value 5

	delete[] array; // use array delete to deallocate array and releases the allocated memory *NEEDED*

	array = NULL; // immidiatly set the array pointer to NULL so it isnt left being a dangling pointer which sucks balls
	
	std::cout << "------------------------------------------------------------------------------" << '\n';

	//initializing dynamicall allocated arrays
	int* array1{ new int[NULL] {} }; 

	int* array2{ new int[5] {9,7,5,3,1} }; // C++11 you can initialize a dynamic array like so 





	

	return 0;
}