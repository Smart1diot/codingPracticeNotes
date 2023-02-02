// 2/2/2023 Determing the highest int member in a array through a loop then printing the highest score out of all the members

#include <iostream>

int main()
{
	constexpr int scores[]{84,92,76,81,56,99}; // scores for each student, class of 5 students
	constexpr int numStudents{ sizeof(scores) / sizeof(scores[0]) }; //Best way to fine number of members is to devide entire size of scores[]array with score[0] the first member

	int maxScore{0}; // variable that keeps track of the highest test score

	for (int student{0}; student < numStudents; student++) // we create a new variable in the forlopp called student that cycles throguh all members in the array using the numStudents
	{
		if (scores[student] > maxScore)	// Checks to see if every members int is larger than the maxScore variable  if yes
		{
			maxScore = scores[student]; // the maxScore Variable that is outside of the loop will now change to the highest score member
		}
	}

	std::cout << "Highest Score: " << maxScore << '\n'; // prints out the largest score out of all students

	return 0;
}

