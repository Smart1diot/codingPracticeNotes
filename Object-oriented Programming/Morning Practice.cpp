#include <iostream>

class Something
{
private:
	int m_value[3]; 

public:
	void setValue1(int value) { m_value[0] = value; } // we set the value of index 0 to 5 in this example

	int getValue1() { return m_value[0]; } // getValue of index 0
};

int main()
{
	Something something; 
	something.setValue1(5);						//setting m_value1 to 5
	std::cout << something.getValue1() << '\n';	//printing m_value1 
}