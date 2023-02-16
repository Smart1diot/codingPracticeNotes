// 2/16/2023 Dynamic memory allocation with new and delete part 2
#include <iostream>

int main()
{
	//Memory leaks happen when the address of the allocated memory gets lost as the program runs
	//causing memory that isnt usable and just builds up till program has ended or crashed.
	//results from ptr going out of scope or we change what the ptr points to after it has allocated memory
	
	//bad example where we forget to delete allocated memory
	int value = 5;
	int* ptr{ new int{} }; //allocated memory
	ptr = &value; // old address lost, memory leak results

	//good exampe where we dont forget to delete allocated memory
	int value1{ 8 };
	int* ptr1{ new int{} };
	delete ptr; //must delete allocated memory before reasigning what the ptr is pointing to
	ptr = &value1;
	
	//Dynamically set allocated memory needs to be deleted before used elsewhere to avoid 
	//memory leaks
	//memory leaks





	return 0;
}
