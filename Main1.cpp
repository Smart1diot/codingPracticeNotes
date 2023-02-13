//2/12/2023 Pointers and arrays

#include <iostream>

void doSomthing(int array[]);
void doSomthing(int* array); //When passing an array into a function perfer '*' operater, because it treats the array like a pointer anyway

int main()
{
	int array[5]{ 9,7,5,3,1 };

	std::cout << "Element 0 has value: " << array[0] << '\n';

	//print the address of the arrays first element
	std::cout << "Element 0 has address: " << &array[0] << '\n';

	//array converts to int and grabs the address of the first member of the array
	std::cout << "The array decays to a pointer holdingn address: " << array << '\n';

	//Deferencing an array returns the first elelemt (element 0)
	std::cout << *array << '\n'; //will print 9!

	//Dereference the pointer to get the value at the memory address the pointer is holding (value of the first element)
	char name[]{ "Jason" }; //c-style string (also an array)
	std::cout << *name << '\n'; //will print 'j'

	//We can assign a pointer to point at the array
	int* ptr{ array };
	std::cout << *array << '\n'; //prints 9
	std::cout << *ptr << '\n'; //prints 9

	//Differences between pointer and fixed arrays
	// if used sizeof(array), will print the size of array like normal
	// if used sizeof(ptr), will print theh size of the pointer

	// if pointer points to array and we print array, will print out the address of first member 
	// if used '&' operater on pointer to array, will print out the address of ptr itself

	


	return 0;
}