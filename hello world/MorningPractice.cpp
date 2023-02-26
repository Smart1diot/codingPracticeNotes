#include <iostream>
#include <vector>
#include <string>
#include <string_view>



int main()
{
	std::vector<std::string_view> words{ "hello world" };

	for (auto member : words)
	{
		if (auto member = "hello world")
		{
			std::cout << 'h';
		}
	}



	return 0;
}