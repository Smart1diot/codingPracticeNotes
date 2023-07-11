#include <iostream>

class Base
{
public:
	//can be accessed by anybody
	int m_public{};
protected:
	//can be acccessed by Base members, friends, and derived classes
	int m_protected{};
private:
	//can only be accessed by Base members and friends (but not
	//derived classes)
	int m_private{};
};

class Derived : public Base
{
public:
	Derived()
	{
		m_public = 1;//allowed: can access public base members from
		//derived class
		m_protected = 2; //allowed: can access protected base 
		//members from derived class
		m_private = 3; //not allowed: can not access private
		//base members from derived class
	}
};

int main()
{
	Base base;
	base.m_public = 1;	//allowed: can access public members
	//from outside class
	base.m_protected = 2;//not allowed: can not access protected
	//members from outside class
	base.m_private = 3;//not allowed: can not access private members 
	//from ouside class


	return 0;
}//
