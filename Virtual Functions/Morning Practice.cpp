#include <iostream>
#include <string_view>

class A
{
public:
	virtual std::string_view getName() { return "A"; }
};

class B final : public A // note use of final specifier here
{
public:
	std::string_view getName() override { return "B"; }
};

//compile error: cannot inherit from final class
//class C :public B;

int main()
{
	return 0;
}//