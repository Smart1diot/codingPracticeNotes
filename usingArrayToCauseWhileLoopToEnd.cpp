//Example using an array member selecter to change bool mid loop causing it to end the loop

#include  <iostream>

struct Rectangle
{
	int length{};
	int width{};
	double cool{};
	bool swap{};
};

Rectangle rec[4]{};

int main()
{
	
	rec[0].length = 1;
	rec[1].width = 2;
	rec[2].cool = 3.6;
	rec[3].swap = true; //Declaring true to bool array member for rectangle object "rec[4]"

	while (true)
	{
		std::cout << "print then end" << '\n';
		rec[3].swap = false; //Using rec[3].swap from object rec to stop loop from continuing 
	}

	return 0;
}
