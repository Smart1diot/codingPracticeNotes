#include <iostream>
#include <vector>
#include <string>
#include <string_view>

void switchCase(const std::vector<char>& cha)
{
	int chaSize{ sizeof(cha) / sizeof(cha[0]) }; // gangster shit! 
	for (int i{ 0 }; i < chaSize; ++i) 
	{
		if (cha[i] == 'l')
		{
			std::cout << 'l'; //prints 'l'
			break;
		}
	}
}

int main()
{
	std::vector<std::string_view> helloWorld{ "hello world" };
	std::vector<char> charHelloWorld{ 'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd' };

	const int oneOone{ 101 };

	for (auto member : helloWorld)
	{
		if (auto member = "hello world")
		{
			std::cout << 'h'; //prints 'h'
		}
	}

	std::cout << static_cast<char>(oneOone); //prints 'e'

	switchCase(charHelloWorld);

	

	return 0;
}