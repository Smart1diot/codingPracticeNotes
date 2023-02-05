#include <iostream>
#include <utility>

int main()
{
	int array[]{6,3,2,9,7,1,5,4,8};								//create an int array with 9 members 
	constexpr int length{sizeof(array) / sizeof(array[0])};					//create a constecpr int length variable with num of all members

	for (int iteration{ 0 }; iteration < length - 1; ++iteration)				//loop that iterates through every member of the array till length-1
	{
		for (int currentIndex{ 0 }; currentIndex < length - 1; ++currentIndex)		//inner loop that deals with the current index in array
		{
			if (array[currentIndex] > array[currentIndex + 1])			//if currentIndex is larger than currentIndex+1
			{
				std::swap(array[currentIndex], array[currentIndex + 1]);	//we swap the values of the currentIndex with the currentIndex+1
			}
		}
	}

												//At this point all of our members in the array have been sorted
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	for (int z{ 0 }; z < length; ++z)							//loop that iterates through all array members
	{
		std::cout << array[z] << ' ';							//prints the current array index value
	}


	return 0;
}
