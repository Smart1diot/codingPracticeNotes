#include <iostream>
#include <vector>

class Thing
{
private:
	int m_x{};
	std::string m_string{};

public:
	Thing(int x = 5, std::string string = "words")
		: m_x{ x }, m_string{ string } {}

	int getNum()
	{
		return m_x;
	}

	std::string getString()
	{
		return m_string;
	}
};

int main()
{
	std::vector<Thing> container{};

	for (int i{ 0 }; i < 50000; ++i)
	{
		container.push_back(Thing{ 10, "words from container" });
	}

	for (int i{ 0 }; i < container.size(); ++i)
	{
		std::cout << container[i].getNum() << " and " << container[i].getString() << " " << i << '\n';
	}

	for (int i{ 49999 }; i > 0; --i)
	{
		container.pop_back();
		std::cout << "popped: " << i << '\n';
	}

	return 0;
}
