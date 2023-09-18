#include <iostream>
#include <vector>

class Thing
{
private:
	std::string tThing{};

public:
	Thing(std::string thing)
		: tThing{ thing } {}

	std::string gettingThing()
	{
		return tThing;
	}
};

int main()
{
	Thing object1{ "Henry" };
	Thing object2{ "Thomas" };

	std::cout << "Names: 2" << '\n';
	std::cout << object1.gettingThing() << '\n';
	std::cout << object2.gettingThing() << '\n' << '\n';

	std::vector<Thing> humanContainer{};
	std::cout << "At the moment the human container has " << humanContainer.size() << " people in it." << '\n';

	for (int i{ 0 }; i < 2; ++i)
	{
		switch (i)
		{
			case 0:
			{
				humanContainer.push_back(object1); break;
			}
			case 1:
			{
				humanContainer.push_back(object2); break;
			}
		}
	}

	std::cout << '\n' << "Now we insert a few people inside..." << '\n';
	std::cout << "and we have a total of " << humanContainer.size() << " people." << '\n';

	return 0;
}