#include <iostream>
#include "Date.h"


int main()

{
	Date today{ 05,03,2023 };
	today.printInfo();

	Date defaultDay;
	defaultDay.printInfo();

	return 0;
}