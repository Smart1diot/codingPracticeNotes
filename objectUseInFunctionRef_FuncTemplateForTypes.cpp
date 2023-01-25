// c++17 type deduction example
#include <iostream>

template <typename T> //Template
struct Triad
{
	T first{};
	T second{};
	T third{};
};

// If using C++17, we need to provide a deduction guide (not required in C++20)
// A Triad with three arguments of the same type should deduce to a Triad<T>
template <typename T> //Template   //*NEW TECH*
Triad(T, T, T) -> Triad<T>;

template <typename T> //Template 
void print(Triad<T>& p) //Function call that uses object reference as a parameter dont foreget it!, can also edit object members this way 
{
	std::cout << '[' << p.first << ", " << p.second << ", " << p.third << ']' << '\n';
}

int main()
{
	Triad t1{ 1, 2, 3};		//Object with all same type
	Triad t2{ 1.2, 3.4, 5.6 };	//Object with all same type

	print(t1);
	print(t2);

	return 0;
}
