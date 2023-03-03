#include <iostream>
#include <array>
#include <numeric> 

enum ItemType
{
	potions,
	tortches,
	arrows,
	totalItems,
};

void countTotalItems(std::array<int, ItemType::totalItems>& items)
{
	std::cout << std::accumulate(items.begin(), items.end(), 0) << '\n';
}

int main()
{
	std::array<int, ItemType::totalItems> Pouch{ 2,5,10 };

	for (int member : Pouch)
	{
		std::cout << member << ' ';
	}

	std::cout << '\n';

	std::cout << "Total number of items being held: ";
	countTotalItems(Pouch);


	return 0;
}