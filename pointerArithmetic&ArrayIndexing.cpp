// 2/13/2023 Pointer arithmetic and array indexing
//Gangster Shit bruh
#include <iostream>
#include <iterator> //for code at the end
#include <algorithm>

int main()
{
	int* findValue(int* begin, int* end, int value);

	//scaling
	int value{ 7 };
	int* ptr{ &value };

	//Move up 4 bytes for each memory address because each int value is 4 bytes
	std::cout << ptr << '\n'; // 0000005FD4CFF7D4 
	std::cout << ptr + 1 << '\n'; // 0000005FD4CFF7D8
	std::cout << ptr + 2 << '\n'; // 0000005FD4CFF7DC
	std::cout << ptr + 3 << '\n'; // 0000005FD4CFF7E0
	std::cout << '\n';
	
	short value1{ 7 };
	short* ptr1{ &value1 };
	//same with short since its 2 bytes, it moves up 2 bytes
	std::cout << ptr1 << '\n'; //000000265C91F764
	std::cout << ptr1 + 1 << '\n'; //000000265C91F766
	std::cout << ptr1 + 2 << '\n'; //000000265C91F768
	std::cout << ptr1 + 3 << '\n'; //000000265C91F76A
	std::cout << '\n';

	//Arrays are laid out sequentially in memory, elements 0,1,2...
	int array[]{ 9,7,5,3,1 };

	std::cout << "Element 0 is at address: " << &array[0] << '\n'; //int has 4 bytes, each iteration moves up 4 bytes in memory for arrays
	std::cout << "Element 1 is at address: " << &array[1] << '\n';
	std::cout << "Element 2 is at address: " << &array[2] << '\n';
	std::cout << "Element 3 is at address: " << &array[3] << '\n';
	std::cout << '\n';

	//That means we can access memory address and therefore access the values within 
	int array1[]{ 9,7,5,3,1 };

	std::cout << &array[1] << '\n'; //print memory address of array element 1
	std::cout << array + 1 << '\n'; //print memory address of array pointer +1

	std::cout << array[1] << '\n'; //prints value under member 1, perfer this one for sure to access members
	std::cout << *(array + 1) << '\n'; //print 7(note the parenthesis required here
	std::cout << '\n';

	int arr[]{ 2,5,4,10,8,20,16,40 };

	int* found{ findValue(std::begin(arr), std::end(arr), 20) }; //pointer that points towards specific value after search function calls

	if (found != std::end(arr))
	{
		std::cout << *found << '\n';
	}



	return 0;
}

int* findValue(int* begin, int* end, int value) //Function that returns specific value from array
{
	for (int * p{begin}; p != end; ++p)
		if (*p == value)
		{
			return p;
		}
	return end;
}
