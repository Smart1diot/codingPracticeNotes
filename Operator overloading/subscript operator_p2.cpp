#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <cassert>
#include <iterator>
#include <algorithm>

class StudentGrade
{
public:
	std::string m_studentName{};
	char m_grade{};


};

class GradeMap
{
private:
	std::vector<StudentGrade> m_map{};

public:
	char& operator[](std::string_view name);
};

char& GradeMap::operator[](std::string_view name)
{
	auto found{ std::find_if(m_map.begin(), m_map.end(),
							[&](const auto& student) { //this is a lambda
							return (student.m_studentName == name);
							}) };

	if (found != m_map.end())
	{
		return found->m_grade;
	}

	// otherwise create a new StudentGrade for this student and add
	// it to the end of our vector
	m_map.push_back({ std::string{name} });

	//and return the element
	return m_map.back().m_grade;
}

int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}
//
