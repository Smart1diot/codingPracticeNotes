// 2/2/2023 Using #include <iostream> to sort members of an array from smallest to biggest then print the numbers out afterward

#include <iostream> 
#include <algorithm> // We got that badass algorithm to be able to sort my array elements

int main()
{
	int array[]{ 30,50,20,10,40 }; // Array variable named array that holds five random numbers

	std::sort(std::begin(array), std::end(array)); // Using the #include <algortihm> we can sort the array in order we chose, from this point on it is sorted 

	for (int i{ 0 }; i < (sizeof(array) / sizeof(array[0])); ++i) // Loop ive done before that loops the amount of times as there are members in the array
	{
		std::cout << array[i] << ' '; // print out the array members based on Index number starting from 0 to 4
	}

	std::cout << '\n';

	return 0;
}
