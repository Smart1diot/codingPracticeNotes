//3/24/2023 - lambda *NOTE:They can be used for anonymous functions where it doesnt polute global space
#include <iostream>
#include <algorithm>
#include <array>
#include <string_view>

int main()
{
	constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

	// Define the function rightwhere we use it
	const auto found{ std::find_if(arr.begin(), arr.end(),
							[](std::string_view str) // here's our lambda, no capture clause
							{
							return (str.find("nut") != std::string_view::npos); // lambda returns a bool value
							}) };

	if (found == arr.end())
	{
		std::cout << "no nuts\n";
	}
	else
	{
		std::cout << "Found nut: " << *found << '\n';
	}

	//--------------------------------------------------------------------
	//We can also use lamba within a variable
	auto isEven{
		[](int i)
		{
			return ((i % 2) == 0);
		}
	};

	return 0;
}
