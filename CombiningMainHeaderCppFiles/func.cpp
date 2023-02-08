#include <iostream> //Allows us to use the standard library in this source file
#include "func.h"	//Connects us to the function templates from this header file

void printAddition(int x, int y) //We define the function here
{
	int total{ x + y };
	std::cout << total << '\n';
}
