#include <iostream>
#include <vector>
std::vector<int> minimalHeaviest(std::vector<int> box)
{
	int weightOne{ 0 };
	int weightTwo{ 0 };

	for (int i{ 0 }; i < box.size(); ++i)
	{
		for (int u{ i + 1 }; u < box.size(); ++u)
		{
			if (box[i] < box[u])
			{
				std::swap(box[i], box[u]);


			}
			
		}
	}

	weightOne += box[0];
	weightTwo += box[1];

	std::cout << weightOne << " " << weightTwo << '\n';

	std::vector<int> heaviestTwo{};

	for (int i{ 0 }; i < 2; ++i)
	{
		if (i == 0)
		{
			heaviestTwo.push_back(weightOne);
		}
		else if (i == 1)
		{
			heaviestTwo.push_back(weightTwo);
		}

	}

	return heaviestTwo;
}

int main()
{
	std::vector<int> object{ 3,5,8,2,9 };

	std::vector<int> boxOfItems{ minimalHeaviest(object) };

	std::cout << boxOfItems[0] << " " << boxOfItems[1] << '\n';

	return 0;
}
