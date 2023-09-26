#include <iostream>
#include <bitset>

int main()
{
	//std::bitset<8> means we want to store 8 bits

	//binary literal for binary 1100 0101
	std::bitset<8> bin1{ 0b1100'0101 };

	//hexadecimal literal for binary 1100 0101
	std::bitset<8> bin2{ 0xC5 };

	std::cout << bin1 << '\n'; 
	std::cout << bin2 << '\n';
	//temp bitset and print it
	std::cout << std::bitset<4>{0b1010};

	return 0;
}