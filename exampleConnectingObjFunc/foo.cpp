#include "pair.h"							//Connect to pair.h for funtions to be used
#include <iostream>							//<iostream> to print shit out

void foo()								// Funtion connected to pair.h 
{
	Pair<int> pair1{ 10,20 };					// Creates a temporary object with both integers are int
	std::cout << pair1.first << '\n';				// We print out the first int 
	std::cout << pair1.second << '\n';				// We print out the second int
	std::cout << max(pair1) << " Is the bigger number." << '\n';	// The max() function gets called and we toss object "pair1" in, this determines the max number out of the 2
}
