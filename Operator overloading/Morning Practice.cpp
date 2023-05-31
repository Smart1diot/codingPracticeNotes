#include <iostream>
#include <cassert>

class Matrix
{
private:
	double m_data[4][4]{}; //4 by 4 two-dimentional array of doubles
	//we cant access array using operator[] because its limited to single parameter

public:
	double& operator()(int row, int col);
	double operator()(int row, int col) const;
	void operator()();
};

double& Matrix::operator()(int row, int col)
{
	assert(col >= 0 && col < 4);
	assert(row >= 0 && row < 4);

	return m_data[row][col];
}

double Matrix::operator()(int row, int col) const
{
	assert(col >= 0 && col < 4);
	assert(row >= 0 && row < 4);

	return m_data[row][col];
}

void Matrix::operator()()
{
	//reset all elements of the matrix to 0.0
	for (int row{ 0 }; row < 4; ++row) // loops that counts by row first
	{
		for (int col{ 0 }; col < 4; ++col)
		{
			m_data[row][col] = 0.0; // sets specific selected element in matrix and resets it to 0.0
		}
	}

}

int main()
{
	Matrix matrix;
	matrix(1, 2) = 4.5; // accessing row 1 and col 2
	std::cout << matrix(1, 2) << '\n'; //printing what is in row 1 col 2 of matrix object
	matrix(); // erase matrix
	std::cout << matrix(1, 2) << '\n'; //prints after reset so result is 0
	// try to limit this operator() since it limits code readablility
	//most times its used for matrix's everything else is probably better written as a funtion
	return 0;
}
//