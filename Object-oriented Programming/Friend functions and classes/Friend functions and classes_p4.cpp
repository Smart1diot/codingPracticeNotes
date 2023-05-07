#include <iostream>

class Storage
{
private:
	int m_nValue{};
	double m_dValue{};
public:
	Storage(int nValue, double dValue)
		: m_nValue{ nValue }, m_dValue{ dValue } {}

	// Make the Display class a friend of Storage
	friend class Display;
};

class Display //Storage class's homie
{
private:
	bool m_displayIntFirst;

public:
	Display(bool displayIntFirst)
		: m_displayIntFirst{ displayIntFirst } {}

	void displayItem(const Storage& storage) // function that access Storage class
	{
		if (m_displayIntFirst)
		{
			std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
		}
		else //displays double first
		{
			std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
		}
	}
};

int main()
{
	Storage storage{ 5,6.7 };
	Display display{ false }; // bool decides which order to display info in

	display.displayItem(storage); // displays info from storage object

	return 0;
}
//try to keep friend functions/classes to a min
