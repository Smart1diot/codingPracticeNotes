#include <iostream>
#include <utility>

int main()
{
	int array[]{6,3,2,9,7,1,5,4,8};
	constexpr int length{sizeof(array) / sizeof(array[0])};

	for (int iteration{ 0 }; iteration < length - 1; ++iteration) 
	{
		for (int currentIndex{ 0 }; currentIndex < length - 1; ++currentIndex) 
		{
			if (array[currentIndex] > array[currentIndex + 1])
			{
				std::swap(array[currentIndex], array[currentIndex + 1]);
			}
		}
	}

	for (int z{ 0 }; z < length; ++z)
	{
		std::cout << array[z] << ' ';
	}


	return 0;
}
