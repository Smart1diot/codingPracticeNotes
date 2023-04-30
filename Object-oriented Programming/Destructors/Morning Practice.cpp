#include <iostream>
#include <cassert>
#include <cstddef>

class IntArray
{
private:
	int* m_array{}; // pointer to memory address of m_array
	int m_length{}; // length of array itself

public:
	IntArray(int length) // Constructor
	{
		assert(length > 0); // assert to make sure length is larger than 0

		m_array = new int[static_cast<std::size_t>(length)] {};
		m_length = length;
	}

	~IntArray() // destructor
	{
		// Dynamically delete the array we allocated ealier
		delete[] m_array;
	}

	void setValue(int index, int value) // sets values of each member in array
	{
		m_array[index] = value;
	}
	
	int getValue(int index) // get value of particular memer in array
	{
		return m_array[index];
	}

	int getLength() // get length of array
	{
		return m_length;
	}
};

int main()
{
	IntArray ar(10); // allocated 10 integers in object "ar"

	// loop that assigned each member of the dynamically allocated array
	// a value based on its current count
	for (int count{ 0 }; count < ar.getLength(); ++count)
	{
		ar.setValue(count, count + 1); // count starts at member 0, and value starts at 0+1
	}

	std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n'; // we print value of member 5, which in index form ends up being value = 4

	return 0;
} // ar is destroyed here, so the ~IntArray() destructor function is called here

// *REMINDER* when initializing an array/container/list class with a length(as oposed to a list of elements)
// example: IntArray ar (10); 