#include <iostream>
#include <string_view>

class A
{
public:
	virtual std::string_view getName() { return "A"; }
};

class B : public A
{
public:
	//note use of final specifier on following line --
	//that makes this function no longer overridable
	std::string_view getName() override final { return "B"; }
	//okay, overrides A::getName(), which is final
};

class C :public B
{
public:
	//std::string_view getName() override { return "C"; }
	//compile error: overrides B::getName(), which is final
};

int main()
{
	return 0;
}//