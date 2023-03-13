#include <iostream>
#include <string_view>
#include <vector>
#include <string>
#include <algorithm>

struct Student
{
	std::string name{};
	int grade{};
};

bool compareGrade(Student a, Student b)
{
	return a.grade > b.grade;
}

int main()
{
	int numberOfStudents{};
	std::cout << "How many students do you wish to enter: ";
	std::cin >> numberOfStudents; // num of students
	
	std::vector<Student> classList{}; // vector of number of students
	classList.resize(numberOfStudents); // we set the number of members in vector

	for (auto& element : classList)
	{
		std::cin >> element.name;
		std::cin >> element.grade;
	}
	std::cout << '\n';

	std::sort(classList.begin(), classList.end(), compareGrade);

	for (auto& element : classList)
	{
		std::cout << element.name << '\n';
		std::cout << element.grade << '\n';
	}

	return 0;
}