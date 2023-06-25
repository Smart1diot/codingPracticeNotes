#include <algorithm> // for std::max
#include <iostream>

class MyString
{
private:
	char* m_data{}; //pointer to each letter to a name
	int m_length{};	//determines h

public:
	MyString(const char* data = nullptr, int length = 0)
		: m_length{ std::max(length,0) } //max picks larger of two int's for word length
	{
		if (length) // only activates if length isnt default to 0
		{
			m_data = new char[static_cast<std::size_t>(length)]; //creates char[length] with user defined length

			for (int i{ 0 }; i < length; ++i)
			{
				m_data[i] = data[i]; //sets char in each index space to fully create string
			}
		}
	}

	~MyString()
	{
		delete[] m_data; //deletes MyString m_data member that we allocated 
	}

	//Overloaded assignment
	MyString& operator=(const MyString& str);

	friend std::ostream& operator<<(std::ostream& out,const MyString& s);
};

//Tip always leave the class that we toss in const
std::ostream& operator<<(std::ostream& out,const MyString& s)
{
	out << s.m_data;
	return out;
}

//A simplistic implementation of operator= (do not use)
MyString& MyString::operator=(const MyString& str)
{
	//self-assignment check
	if (this == &str)
	{
		return *this;
	}

	//if data exist in the current string, delete it
	if (m_data)
	{
		delete[] m_data;
	}

	m_length = str.m_length;	//new object copied str.m_length onto new m_length
	m_data = nullptr;			//new object m_data has nullptr since its a pointer holding the bits we need

	//copy the data from str to the implicit object
	if (m_length)
	{
		m_data = new char[static_cast<std::size_t>(str.m_length)];
	}

	for (int i{ 0 }; i < str.m_length; ++i)
	{
		m_data[i] = str.m_data[i];
	}

	//return the existing object so we can chain this operator
	return *this;
}

int main()
{
	MyString alex("Alex", 5); // Meet Alex
	MyString employee;
	employee = alex; //Alex is our newest employee

	std::cout << employee << '\n';	//prints MyString employee "Alex"

	std::cout << alex << '\n';		//prints MyString alex "Alex
	alex = alex;					//**object copies from itself causes errors
	std::cout << alex << '\n';		//**prints nonsense

	return 0;
}
//
