#include <iostream>
#include <vector>
#include <string>
#include <string_view>

void printLetter(const std::vector<int>& v)
{
	for (char i : v)
	{
		if (i == 'l')
		{
			std::cout << i;
		}
	}
}

int main()
{
	std::vector<std::string_view> words{ "hello world" };
	int oneOone{ 101 };

	for (auto member : words)
	{
		if (auto member = "hello world")
		{
			std::cout << 'h';
		}
	}

	int s{ 'e' };

	std::cout << oneOone;





	return 0;
}