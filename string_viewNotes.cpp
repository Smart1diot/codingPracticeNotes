// 2/12/2023 string_view notes

#include <iostream>
#include <string_view> //c++17 only
#include <iterator> //for std::size
#include <cstring>
#include <string>

int main()
{
	std::string_view str{ "Trains are fast!" }; //string_view array is an array with multiple strings

	std::cout << str.length() << '\n'; //16
	std::cout << str.substr(0, str.find(' ')) << '\n'; //Trains (isolates a word, very usefull)
	std::cout << (str == "Trains are fast!") << '\n'; //Equals true, prints value 1 we can compare strings

	//Since c++20
	std::cout << str.starts_with("Boots") << '\n'; // 0 Compares to see if string begins with same prefix 
	std::cout << str.ends_with("fast!") << '\n'; // 1 compares to see if string ends with same prefix

	std::cout << str << '\n'; //prints string like normal

	std::cout << '\n' << "-----------------------------------------------------" << '\n';

	//Doesnt create a copy of the string, if we change the viewed string, the changes are reflected in the std::string_view
	char arr[]{ "Gold" }; //char array is an array with mulitple letters
	std::string_view gol{ arr };

	std::cout << gol << '\n'; //Gold

	arr[3] = 'f';

	std::cout << arr << '\n'; //Golf both share the same string
	std::cout << gol << '\n'; //Golf

	std::cout << '\n' << "-----------------------------------------------------" << '\n';


	//Creating a std::string evertime we want to pas a string_view as a c-style string is expenisve to should be avoided if possible
	//std::string_view doesnt use null terminators to mark the end of a string, it knows where the string ends because it keeps track of its length
	//no null-terminator
	char vowels[]{'a', 'e', 'i', 'o', 'u'};

	//vowels isnt null-terminated. We need to pass the length manually.
	//Because vowels is an array, we can use std::size to get its length
	std::string_view vow{ vowels, std::size(vowels) };

	std::cout << vow << '\n'; //This is safe. std::cout knows how to print std::string_view

	std::cout << '\n' << "-----------------------------------------------------" << '\n';

	//converting a std::string_view to a c-style string

	std::string_view sv{ "balloon" };

	sv.remove_suffix(3);

	//create a std::string from the std::string_view
	std::string ball{ sv };

	//get the null-terminated c-style string
	auto szNullterminated{ ball.c_str() }; //looks like we use a function within the initializer for ball string

	//Pass the null-terminated string to the function that we want to use
	std::cout << ball << " has " << std::strlen(szNullterminated) << " letter(s)" << '\n';

	std::cout << '\n' << "-----------------------------------------------------" << '\n';

	//For Functions, Perfer std::string_view over const std::string& unless tossing another c-style string in with it

	void doSomthing(const std::string&);
	void doSomthing(std::string_view); //perfer this in most cases when passing strings to functions

	return 0;
}
