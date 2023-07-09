//std::initializer_list is fucking badass

#include <iostream>
#include <initializer_list> //
#include <cassert>
//std::initializer_list is passed down like string_view, by value

class IntArray
{
private:
	int m_length{};
	int* m_data{};
public:
	IntArray() = default;

	IntArray(int length)
		: m_length{ length }
		, m_data{ new int[length] {} }
	{
	}

	//Allow IntArray to be initialized via list initialization
	IntArray(std::initializer_list<int> list)
		: IntArray(static_cast<int>(list.size()))//returns size_t so static_cast is needed
		//use delegating constructor to set up intial array
	{
		//Now initialize our array from the list
		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	~IntArray()
	{
		delete[] m_data;
		//we don't need to set m_data to null or m_length to 0 here,
		//since the object will be destroyed immediately after this
		//function anyway
		//but for future code might be different
	}

	//to avoid shallow copies of class
	IntArray(const IntArray&) = delete;

	//more to avoid shallow copies of class
	IntArray& operator=(const IntArray& list) = delete;

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const { return m_length; }
};

int main()
{
	IntArray array{ 5,4,3,2,1 }; //initializer list

	for (int count{ 0 }; count < array.getLength(); ++count)
	{
		std::cout << array[count] << ' ';
	}

	return 0;
}

//*NOTES*
//IntArray a1(5);   uses IntArray(int), allocates an array of size 5
//IntArray a2{ 5 }; uses IntArray<std::initializer_list<int>, allocates array of size 1

//1. Provide an overloaded list assignment operator
//2. Provide a proper deep - copying copy assignment operator
//3. Delete the copy assignment operator

//