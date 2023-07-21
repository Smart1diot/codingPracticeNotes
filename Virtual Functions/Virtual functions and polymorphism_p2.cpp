#include <iostream>
#include <string_view>

class A
{
public:
	virtual std::string_view getName() const { return "A"; }
};

class B : public A
{
public:
	virtual std::string_view getName() const { return "B"; }
};

class C : public B
{
public:
	virtual std::string_view getName() const { return "C"; }
};

class D : public C
{
public:
	virtual std::string_view getName() const { return "D"; }
};

int main()
{
	C c{};
	A& rBase{ c };

	//only objects from A to C will be considered
	//with the most derived definition in that
	//range
	std::cout << "rBase is a " << rBase.getName() << '\n';
	//prints "rBase is a C"

	return 0;
}
