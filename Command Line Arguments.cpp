// 3/22/2023 - Command line arguments
//  Program MyArgs
#include <iostream>

int main(int argc, char* argv[])
{
	std::cout << "There are " << argc << " arguments:" << '\n';

	// loop through each argument and print its number and value
	for (int count{ 0 }; count < argc; ++count)
	{
		std::cout << count << ' ' << argv[count] << '\n';
	}
	
}
