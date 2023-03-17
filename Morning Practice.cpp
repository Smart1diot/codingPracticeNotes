// 3/17/2023 std::vector capacity and stack behavior
#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack)
{
	for (auto element : stack)
	{
		std::cout << element << ' ';
	}

	std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}

int main()
{
	std::vector<int> array{};
	array = { 0,1,2,3,4 };	// Length: 5	capacity: 5
	std::cout << "length: " << array.size() << " capacity: " << array.capacity() << '\n';
	
	for (int member{ 0 }; member < 5; ++member) // Best way to access members in vector array
	{
		std::cout << array[member] << ' ';
	}

	std::cout << '\n';

	array = { 9,8,7 };	// Length: 3	capacity: 5
	std::cout << "length: " << array.size() << " capacity: " << array.capacity() << '\n';

	for (int member{ 0 }; member < 3; ++member)
	{
		std::cout << array[member] << ' ';
	}

	std::cout << '\n';
	printStack(array);

	std::cout << '\n' << '\n';

	//------------------------------------------------------------------------------------------
	// Stack behavior with std::vector

	// psuh_back() pushes an element on the stack.
	// back() returns the value of the top element on the stack.
	// pop_back(0 pops an element off the stack.

	std::vector<int> stack{};

	printStack(stack);

	stack.push_back(5); // push_back() pushes an element on the stack
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	std::cout << "top: " << stack.back() << '\n'; 

	stack.pop_back(); // pop_back() pops an element off the stack
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack); // capacity at this point remains 3 but length is 0, 0 members.

	// We do 3 different resizes and that takes up more computing power and is slower to boot!.
	std::cout << '\n' << '\n';
	//------------------------------------------------------------------------------------------
	// We can tell the vector to allocate a certain amount of capacity up front using the
	// reserve() function:

	std::vector<int> stack2{};
	
	stack2.reserve(5); // Set the capacity to (at least) 5

	printStack(stack2); // length: 0	capacity: 5

	stack2.push_back(5);
	printStack(stack2);// length: 1		capacity: 5

	stack2.push_back(3);
	printStack(stack2);// length: 2		capacity: 5

	stack2.push_back(2);
	printStack(stack2);// lenght: 3		capacity: 5

	std::cout << "top: " << stack2.back() << '\n';

	stack2.pop_back();
	printStack(stack2);

	stack2.pop_back();
	printStack(stack2);

	stack2.pop_back();
	printStack(stack2);

	//We set the capacity to 5 and didnt change over the lifetime of the program
	std::cout << '\n' << '\n';
	//------------------------------------------------------------------------------------------
	//When a vector is resized, the vector may allocate more capacity than is needed. 
	//to minimize the number of resize operations needed.

	std::vector v{ 0,1,2,3,4 };
	std::cout << "size: " << v.size() << " cap: " << v.capacity() << '\n'; //length 5	capacity 5

	v.push_back(5); //add another element
	std::cout << "size: " << v.size() << " cap: " << v.capacity() << '\n'; //length 6	capacity 7


	return 0;
}