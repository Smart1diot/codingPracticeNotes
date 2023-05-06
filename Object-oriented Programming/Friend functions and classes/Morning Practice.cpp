#include <iostream>

class Accumulator
{
private:
	int m_value{ 0 };

public:
	void add(int value) { m_value += value; }

	//Make the reset() function a friend of this class
	friend void reset(Accumulator& accumulator);

	friend void printData(Accumulator& accumulator);
};

//reset() is now a friend of the Accumulator class
void reset(Accumulator& accumulator) // now we are given access to private members
{
	accumulator.m_value = 0;
}

void printData(Accumulator& accumulator)
{
	std::cout << accumulator.m_value << '\n';
}

int main()
{
	Accumulator acc;

	printData(acc);

	acc.add(5);

	printData(acc);

	reset(acc);

	printData(acc);

	return 0;
}