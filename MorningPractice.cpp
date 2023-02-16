// 2/16/2023 Dynamic memory allocation with new and delete part 1
#include <iostream>

int main()
{
	new int; //dynamically allocate an integer (and discard the result)

	int* ptr{ new int }; //dynamically allocate an integer and assign the address to ptr so we can access it later

	*ptr = 7; // assign value of 7 to allocated memory
	int eight{ 8 }; //regular int variable with 8 already inside for comparison

	//without a pointer to hold the address of the memory thay was just allocated, we'd have no way to 
	//access the memory that was just allocated for us
	//unlike static or automatic memory, the program itself is responsible for requesting and 
	//disposing of dynamicated allocated memory

	//Initializing a dynamically allocated variable
	int* ptr1{ new int(5) }; // use direct initialization
	int* ptr2{ new int {6} }; //use uniform initialization 

	//Deleting a sing varaible
	std::cout << *ptr << '\n'; //ptr still assigned 7 from ealier
	delete ptr; // return the memory pointed to by ptr to the operating system
	ptr = nullptr; //set ptr to be a null pointer, holding nothing for now
	//from this point onward the ptr isnt holding the memoringn it was previously appointed to 

	//example of reassigning the pointer to another memory address sized int 4bytes then assigning value 9 to it the printing it out
	delete ptr;
	ptr = new int;
	*ptr = 9;
	std::cout << *ptr << '\n';

	//set ptrs to nullptr immidiatly so its not a dangling ptr

	int* value{ new (std::nothrow) int{} }; //ask for an integers worth of memory
	if (!value) //handle case where new returned null
	{
		std::cerr << "Could not allocate memory" << '\n';
	}


	return 0;
}