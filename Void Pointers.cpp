// 2/22/2023 Void pointers - void pointers avoid type checking when in function parameters, shoulder be avoided unless need, there are better ways to do these things
#include <iostream>
#include <cassert> // for error checking for default in switch

enum class Type
{
	tInt,
	tFloat,
	tCString,
};

void printValue(void* ptr, Type type)
{
	switch (type)
	{
	case Type::tInt:
	{
		std::cout << *static_cast<int*>(ptr) << '\n'; // cast to int pointer and perform indirection
		break;
	}
	case Type::tFloat:
	{
		std::cout << *static_cast<float*>(ptr) << '\n'; // cast to float pointer and perform indirection
		break;
	}
	case Type::tCString:
	{
		std::cout << *static_cast<char*>(ptr) << '\n'; // cast to char pointer (no indirection)
		break;
		//std::cout will treat char* as a c-style string 
		//if we were to perform indirection through the results, then we'd just print the single char that ptr is point to
	}
	default: 
	{
		assert(false && "type not found");
		break;
	}
	}
}

int main()
{
	int nValue{ 5 };
	float fValue{ 7.5f };
	char szValue[]{ "Mollie" };

	printValue(&nValue, Type::tInt);
	printValue(&fValue, Type::tFloat);
	printValue(szValue, Type::tCString); //for strings we dont add the '&' symbol 

	return 0;
}
