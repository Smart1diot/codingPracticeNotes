//2/6/2023 Multidimentional Arrays and accessing them

#include <iostream>

int main()
{
	int array1[3][5]
	{
		{1,2,3,4,5},        //0,1,2,3,4   how to access the values in the array
		{6,7,8,9,10},		//0,
		{11,12,13,14,15},	//1,
	};						//2,

	int array2[][5]
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
	};

	int array3[3][5]{};
	
	int numRows{4}; //num of rows in reference to array2
	int numCols{5}; //num of columns in reference to array2


	//Printing all the values loop for the array2
	for (int row{ 0 }; row < numRows; ++row)		//step through the rows in the array 
	{
		for (int col{ 0 }; col < numCols; ++col)	//step through each element in the row
		{
			std::cout << array2[row][col] << ' ';
		}
	}

	std::cout << '\n';

	std::cout << array2[2][1] << '\n'; // manually access the value behind the multidimentional array and print

	return 0;
}
