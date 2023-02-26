// 2/26/2023 Intro to standard library algorithms - Favor using functions from the algorithms library over writing my own functionality to do the same thing
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

//our function will return true if the element matches
bool containsNut(std::string_view str)
{
	//std::string_view::find returns std::string_view::npos if it doesnt find
	//the substring. Other wise it returns index where the substring occurs 
	//in str.
	return(str.find("nut") != std::string_view::npos);
}

bool greater(int a, int b)
{
	// order @a before @b if @a is greater than @b
	return (a > b);
}

void doubleNumber(int& i) //dereference value 
{
	i *= 2; //i * 2
}

int main()
{
	// Using std::find to find an element by value
	std::array arr{ 13,90,99,5,40,80 };

	std::cout << "Enter a value to search for and replace with: " << '\n';
	int search{};
	int replace{};
	std::cin >> search >> replace;

	// input validation omitted

	// std::find returns an iterator pointing to the found element (or the end of the container)
	// we''ll store it in a variable, using type inference to deduce the type of
	// the iterator (since we don't care)
	auto found{ std::find(arr.begin(), arr.end(), search) };

	// algorithms that dont find what they were looking for return the end iterator.
	// we can access it by using the end() member function.
	if (found == arr.end())
	{
		std::cout << "Could not find " << search << '\n';
	}
	else
	{
		// override the found element
		*found = replace;
	}

	//prints all members after the change of searched int
	for (int i : arr)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n' << '\n';

	//---------------------------------------------------------------------------

	//Using std::find_if to find an element that matches some condition
	std::array<std::string_view, 5> wordArr{ "apple", "banana", "walnut", "lemon", "peanut"};

	//scan our array to see if any elements contain the "nut" substring
	auto foundWord{ std::find_if(wordArr.begin(), wordArr.end(), containsNut) };

	if (foundWord == wordArr.end()) //if foundWord == the end of the array, it acitvates this line of code
	{
		std::cout << "No nuts" << '\n';
	}
	else // otherwise if it does find the text "nut", it returns the text "Found " followed by dereferencing the first pointer member that it finds with the word "nut"
	{
		std::cout << "Found " << *foundWord << '\n';
	}

	// Using std::count and std::count_if to count how many occurrences there are
	auto nuts{ std::count_if(wordArr.begin(), wordArr.end(), containsNut) };

	std::cout << "Counted " << nuts << " nut(s)"; //prints the returns numbers of words with the word "nut" 
	std::cout << '\n' << '\n';

	//---------------------------------------------------------------------------

	//Using std::sort to custom sort
	std::array numArray{ 13,90,99,5,40,80 };

	// pass greater to std::sort
	std::sort(numArray.begin(), numArray.end(), std::greater<int>{}); //standard library has a greater comparison to use std::greater<PlaceHolderDATATYPE>{}

	for (int i : numArray)
	{
		std::cout << i << ' ';
	}

	std::cout << '\n' << '\n';

	//---------------------------------------------------------------------------

	// Using std::for_each to do somthing to all elements of a container
	std::array numsToDouble{ 1,2,3,4 };

	std::for_each(numsToDouble.begin(), numsToDouble.end(), doubleNumber);

	for (int i : numsToDouble)
	{
		std::cout << i << ' ';
	}

	//Like many algorithms, std::for_each can be parallelized to achieve faster processing,
	//making it better suited for large projects and big data than a range-based for-loop
	//for-loops still nice for easy quick prints of lists so we still cool.
	std::cout << '\n';


	return 0;
}