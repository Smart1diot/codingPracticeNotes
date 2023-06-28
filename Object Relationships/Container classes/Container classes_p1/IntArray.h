#pragma once
#include <cassert> // for assert()

class IntArray
{
private:
	int m_length{}; //simple data type we are using for the class
	int* m_data{};	//pointer because we want our array 
					//to be able to change in size

public:
	IntArray() = default;//Constructor that creates empty array

	IntArray(int length) :	//Consntructor that allow us to construct 
							//an array of a predetermined size
		m_length{ length }
	{
		assert(length >= 0);

		if (length > 0)
			m_data = new int[length] {};
	}

	~IntArray() //Destructor which simply deallocates any dynamically allocated data
	{
		delete[] m_data;

		//we don't need to set m_data to null or
		//m_length to 0 here, since the object will be
		//destroyed immediately after this function anyway
	}

	void erase() //erases the array and sets the length to 0
	{
		delete[] m_data;

		//We need to make sure we set m_data to nullptr here,
		//otherwise it will be let pointing at deallocated memory!
		m_data = nullptr;
		m_length = 0;
	}

	int& operator[](int index) //returns data type set in specific index
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const { return m_length; } //returns num of array members
};
//
