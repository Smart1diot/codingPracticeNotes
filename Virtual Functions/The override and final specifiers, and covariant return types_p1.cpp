#include <iostream>
#include <string_view>

class A
{
public:
	virtual std::string_view getName1(int x) { return "A"; }
	virtual std::string_view getName2(int x) { return "A"; }
	virtual std::string_view getName3(int x) { return "A"; }
};

class B : public A
{
public:
	//virtual std::string_view getName1(short int x) override { return "B"; } // note: parameter is a short int, will not compile
	//virtual std::string_view getName2(int x) const override { return "B"; } // note: function is const, will not compile
	std::string_view getName3(int x) override { return "B"; }//okay, function is an override of A::getName3(int)
};

int main()
{
	B b{};
	A& rBase{ b };
	std::cout << rBase.getName1(1) << '\n';
	std::cout << rBase.getName2(2) << '\n';
	std::cout << rBase.getName3(3) << '\n';

	return 0;
}//
