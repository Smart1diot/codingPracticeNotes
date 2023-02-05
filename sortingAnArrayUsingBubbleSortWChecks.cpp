// 2/5/2023  Bubble sort 

#include <iostream>
#include <utility>

int main()
{
	int array[]{6,3,2,9,7,1,5,4,8};  
	constexpr int length{sizeof(array) / sizeof(array[0])};

	for (int iteration{ 0 }; iteration < length - 1; ++iteration)						 
	{
		int endOfArrayIndex{ length - iteration };
		bool swapped{ false };

		for (int currentIndex{ 0 }; currentIndex < endOfArrayIndex - 1; ++currentIndex) 
		{
			if (array[currentIndex] > array[currentIndex + 1])
			{
				std::swap(array[currentIndex], array[currentIndex + 1]);
				swapped = true;
			}
		}
		if (!swapped)
		{
			std::cout << "Early termination in iteration: " << iteration + 1 << '\n';
			break;
		}
	}

	for (int z{ 0 }; z < length; ++z)
	{
		std::cout << array[z] << ' ';
	}


	return 0;
}
