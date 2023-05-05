#include <iostream>
#include <array>

class Something
{
public:
	static int s_value; // declares the static member variable
};
int Something::s_value{ 1 }; // defines the static member variable, typically found in .cpp file under class

class Whatever
{
public:
	static const int w_value{ 3 }; // a static const int can be decalred and initialized directly
};

class Object
{
public:
	static constexpr double o_value{4.4}; 

	static constexpr std::array<int, 3>
		s_array{ 1,2,3 };	// this even works for classes that
							// support constexpr initialization
};

int main()
{
	//*NOTE*
	// we're no instantiating any objects of type Something

	std::cout << Something::s_value << '\n'; // prints 1 from class

	Something::s_value = 2; // changes s_value from class

	std::cout << Something::s_value << '\n'; // prints 2 from class

	std::cout << Whatever::w_value << '\n'; // print 3 from class

	std::cout << Object::o_value << '\n'; // print 4.4 from class

	for (int i{ 0 }; i <= 2; ++i) // prints members from s_array in class Object 
	{
		std::cout << Object::s_array[i] << ' ';
	}
	std::cout << '\n';

	return 0;
}
//*NOTE* 
// Access static members by class name rather than through an object of the class