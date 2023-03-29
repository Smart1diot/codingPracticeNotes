#include <iostream> // for std::size()

class IntArray
{
private:
	int m_array[10]; // user can not access this directly any more

public:
	void setValue(int index, int value) // function that helps us establish values depending on index we want
	{
		// if the index is invlaid, do nothing
		if (index < 0 || index >= std::size(m_array))
			return;

		m_array[index] = value;
	}
};

int main()
{
	IntArray array;

	array.setValue(8, 15); //valid, sets index 8 to value 15
	array.setValue(15, 420); //invalid literally nothing happens after computing function 

	return 0;
}
