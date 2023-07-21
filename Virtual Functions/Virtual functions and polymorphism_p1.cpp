#include <iostream>
#include <string_view>

class Base
{
public:
	virtual std::string_view getName() const { return "Base"; }
};

class Derived : public Base
{
public:
	virtual std::string_view getName() const { return "Derived"; }
};

int main()
{
	Derived derived{}; 

	Base& rBase{ derived };//only has viewing access to Base& 
	//unless using virtual functions which calls 
	//most recent derived definition

	std::cout << "derived is a " << derived.getName() << '\n';
	std::cout << "rBase is a " << rBase.getName() << '\n';

	return 0;
}//
