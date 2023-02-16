// 2/16/2023 c-stle string symbolic constants
#include <iostream>

const char* getName() //function call returning "Alex" string literal because its in static memory
{
	return "Alex"; //"Alex" will not be destroyed when getName() terminates so caller can still successfully access it
}

int main()
{
	char myName0[]{ "Alex" }; //fixed array
	const char* myName1{ "Alexa" }; //pointer to string literal, can only do it with const variables
	//the compiler places the string into read-only memory somewhere, because string ilterals cant be changed it must be const

	//for opimization purposes, mutiple sting literals may be consolidates into a singe value
	const char* myName2{ "Alexa" };

	std::cout << myName0 << '\n';
	std::cout << myName1 << '\n'; //--- Both of these share the same memory address and they have static duration
	std::cout << myName2 << '\n'; //--| so it lives till the end of the program so we can do stuff like...

	std::cout << getName() << '\n'; //function call getName() with no parameters

	//c-style strings are used in a lot of old or low-level code, because they have a very small memory footprint.
	//Modern code should favor use std::string or :: string_view as those provide safe and easy access to the string

	//std::cout handles pointers of different types
	int nArray[5]{ 9,7,5,3,1 }; 
	char cArray[]{ "Hello!" };
	const char* myName3{ "Alexa" }; 

	std::cout << nArray << '\n'; //nArray will decay to type int* and prints the memory address of array
	std::cout << cArray << '\n'; //decays from array to char* and prints the text
	std::cout << myName3 << '\n';//name is already type char* and prints

	//programs can essentially go wrong if trying to print memory address like this
	char c{ 'Q' };
	std::cout << &c;
	//in this program we want to print the memory address of c but std::cout tries printing string instead
	//essentially also printing what follows in memory after string till it reaches a '0' which it treats like null to end
	//becarefull of wanting to print char variables memory addresses
	

	return 0;
}
