#include <iostream>

class Something
{
private:
	static inline int s_idGenerator{1}; 
	int m_id{};

public:
	Something() // grabss the next value from the id generator
		: m_id{ s_idGenerator++ } {}

	int getID() const { return m_id; } // returns m_id value
};

int main()
{
	Something first;
	Something second;
	Something third;

	std::cout << first.getID() << '\n';
	std::cout << second.getID() << '\n';
	std::cout << third.getID() << '\n';

	return 0;
}