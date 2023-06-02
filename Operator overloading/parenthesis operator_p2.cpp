//parenthesis operator example 1
#include <iostream>
#include <string>
#include <string_view>

class MyString
{
private:
	std::string m_s{};

public:
	MyString(std::string s) : m_s{ s } {}
	MyString operator()(int start, int end);

	friend std::ostream& operator<<(std::ostream& out, const MyString& s);
};

std::ostream& operator<<(std::ostream& out, const MyString& s)
{
	out << s.m_s << '\n';
	return out;
}

MyString MyString::operator()(int start, int end)
{
	return m_s.substr(start, end);
}

int main()
{
	MyString s{ "Hello, world!" };

	std::cout << s(7, 5) << '\n';

	return 0;
}
//
