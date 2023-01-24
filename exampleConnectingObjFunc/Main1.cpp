//How to connect and use header,cpp files as well as use structs to create obejcts and do as we wish with them

#include <iostream> 
#include "pair.h" //Connect the pair.h to be able to use both the pair.h struct, and function templates as well as connect the foo.cpp file to use the 'void max()' function

void foo();

int main()
{
	Pair<double> pair2{ 2.2, 8.9 }; //Creates a Pair object with type double named 'pair2'
	std::cout << pair2.first << '\n'; //Prints out first type
	std::cout << pair2.second << '\n'; //Prints out secondn type
	std::cout << max(pair2) << " Is the bigger number." << '\n'; //function calls 'max()' and we toss in 'pair2' and prints out larger of the two

	std::cout << "--------------------------------------------------------------------------" << '\n'; // just a line bruh

	foo(); //function call that creates its own object named 'pair1' and does the same action as what we just did

	//std::cout << max(pair1); We cannot use the object created in the function() in main() because it has been destroyed but we can use foo() to keep creating the same 'pair1' print

	return 0; //the program ends
}

