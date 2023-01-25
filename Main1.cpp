// c++17 type deduction example
#include <iostream>

template <typename T>
struct Triad
{
	T first{};
	T second{};
	T third{};
};

template <typename T>
void print(Triad<T> p)
{
	std::cout << '[' << p.first << ", " << p.second << ", " << p.third << ']' << '\n';
}

int main()
{
	Triad t1{ 1, 2, 3};
	Triad t2{ 1.2, 3.4, 5.6 };

	print(t1);
	print(t2);

	return 0;
}