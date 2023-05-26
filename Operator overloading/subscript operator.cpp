#include <iostream>
#include <cassert>	// assert()
#include <iterator> // std::size()

class IntList
{
private:
	int m_list[10]{};

public:
	int& operator[](int index);			// non const version
	int operator[](int index) const;	// const version
};

int& IntList::operator[](int index)
{
	assert(index >= 0 && index < std::size(m_list)); // error handling to make sure we dont reach for a out of bounds memer in the array

	return m_list[index];
}

int IntList::operator[](int index) const
{
	return m_list[index];
}

int main()
{
	IntList list{};
	list[2] = 3; // set value
	std::cout << list[2] << '\n';

	return 0;
}
