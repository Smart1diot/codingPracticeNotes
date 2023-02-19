// 2/19/2023 Morning Practice for-each loops with an array to find a name in list
#include <iostream>
#include <string>
#include <string_view>

int main()
{
	std::string_view namesContainer[] //string_view
	{
		"Alex",
		"Betty",
		"Caroline",
		"Dave",
		"Emily",
		"Fred",
		"Greg",
		"Holly",
	};

	std::cout << "Enter a name: ";
	std::string userSubmitedName{};
	std::getline(std::cin, userSubmitedName); //gangster shit dawg

	bool found{ false }; //bool is great option for string search to avoid string copies being made

	for (std::string_view name : namesContainer) //use std::string_veiw to avoid making expensive copies if a std::string is tossed in there like I did.
	{
		if (userSubmitedName == name)
		{
			found = true;
			break;
		}
	}

	if (found)
	{
		std::cout << userSubmitedName << " was found." << '\n';
	}
	else
	{
		std::cout << userSubmitedName << " was not found." << '\n';
	}

	std::cout << '\n';

	return 0;
}
