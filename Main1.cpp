#include <iostream>

namespace animals
{
	enum Animals
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,

		totalnumberofanimals,
	};
};

int main()
{
	int animals[animals::Animals::totalnumberofanimals]{2,4,4,4,2,0,};

	std::cout << "An elephant has " << animals[animals::Animals::elephant] << " legs." << '\n';


	return 0;
}