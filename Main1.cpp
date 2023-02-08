// 2/8/2023 Personal Text Container Method!

#include <iostream>
#include <string_view>

int main()
{
	std::string container[][1]
	{
		{"hello world"},
		{"second line of text"},
	};

	std::cout << container[0][0] << '\n';
	std::cout << container[0][1] << '\n';
	
	
	return 0;
}