// 2/24/2023 Intro to iterators
#include <array>
#include <cstddef>
#include <iostream>
#include <vector>

int main()
{
	std::array<int, 7> data{ 0,1,2,3,4,5,6 }; // pre-c++17 method for older stuff
	std::size_t length{ std::size(data) }; //note: size_t can be accessed using std::size_t

	//while-loop with explicit index
	std::size_t index{ 0 };
	while (index < length)
	{
		std::cout << data[index] << ' ';
		++index;
	}
	std::cout << '\n';

	// for-loop with explicit index
	for (index = 0; index < length; ++index) //personally most familier with
	{
		std::cout << data[index] << ' ';
	}

	std::cout << '\n';

	// for-loop with pointer (Note: ptr cant be const, because we increment it)
	for (auto ptr{ &data[0] }; ptr != (&data[0] + length); ++ptr) 
	{
		std::cout << *ptr << ' ';
	}

	std::cout << '\n';

	//ranged-based for loop
	for (int i : data) //good way to access all members at once (if making a list probably sort before hand if it matters
	{
		std::cout << i << ' ';
	}

	std::cout << '\n' << '\n';

	//-------------------------------------------------------------------

	//Pointers as an iterator

	auto begin{ &data[0] };
	// note that this points to one spot beyond the last element
	auto end{ begin + std::size(data) };

	// for-loop with pointer
	for (auto ptr{ begin }; ptr != end; ++ptr) //interesting method using the pointer, gotta try using it more
	{
		std::cout << *ptr << ' ';
	}

	std::cout << '\n' << '\n';;

	// slightly more improved version using array.begin() and array.end()
	auto beginButCooler{ data.begin() };
	auto endButCooler{ data.end() };

	for (auto p{ begin }; p != end; ++p)
	{
		std::cout << *p << ' '; //indirection to get value of current element
	}

	std::cout << '\n' << '\n';

	//-------------------------------------------------------------------

	// Back to range-based for loops
	for (int i : data)
	{
		std::cout << i << ' ';
	}

	std::cout << '\n' << '\n'; // As I write my notes I realized (ranged-based loops = God tier)

	//-------------------------------------------------------------------

	// Iterator invalidation (dangling iterators)
	std::vector v{ 1,2,3,4,5,6,7 };
	
	auto it{ v.begin() };

	++it; // move to second element
	std::cout << *it << '\n'; // ok: prints '2'

	v.erase(it); //earse the element currently being iterated over

	//earase() invalidates iterators to the erased element (and subsequent elements)
	// so iterator "it" is now invalidated

	++it; // undefined behavior
	std::cout << *it << '\n'; // undefined behavior 

	// Still builds but becarefull of iterator invalidation (dangling iterators)

	return 0;
}
