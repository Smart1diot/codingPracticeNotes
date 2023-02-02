// 2/2/2023 How to use loops to do some sort of calculations with each member of the array... USEFULL shit dawg

#include <iostream>

int main()
{
	constexpr int scores[]{ 84,92,76,81,56 }; //set the scores for five students?
	const int numStudents{ sizeof(scores) / sizeof(scores[0]) }; // preC++17 This somehow finds the numbers of members inside of the score[]array 

	std::cout << "sizeof(scores): " << sizeof(scores) << '\n';
	std::cout << "sizeof(scores[0]): " << sizeof(scores[0]) << '\n';
	std::cout << "numStudents: " << numStudents << '\n';

	std::cout << "----------------------------------------------------------------------------------------" << '\n' << '\n';

	int totalscore{ 0 };

	// use a loop to calculate totalScore
	// **Introduce a new variable withing the loop "int student" to add the total of all students scores 
	for (int student{ 0 }; student < numStudents; student++)
	{
		totalscore += scores[student]; // we add the total score for each student after each iteration change
	}

	std::cout << "Total Score: " << totalscore << '\n'; // prints total score so far to test if it works adding the totals up

	std::cout << "-----------------------------------------------------------------------------------------" << '\n' << '\n';

	auto averagescore{ totalscore / numStudents }; // final variable that calculates the average score of all students

	std::cout << "Average Score for every student: " << averagescore << '\n'; // we finalize this work by printing the class average score

	return 0;
}





