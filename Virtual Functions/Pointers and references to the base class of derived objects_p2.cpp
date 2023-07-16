#include <iostream>
#include <string_view>
#include <string>

class Animal
{
protected:
	std::string m_name;

	//We're making this constructor protected because
	//we don't want people creating Animal objects directly,
	//but we still want derived classes to be able to use it.
	Animal(std::string_view name)
		: m_name{name}
	{}

	//to prevent slicing*			*later topic
	Animal(const Animal&) = default;
	Animal& operator=(const Animal&) = default;

public:
	std::string_view getName() const { return m_name; }
	std::string_view speak() const { return "???"; }
};

class Cat : public Animal
{
public:
	Cat(std::string_view name)
		: Animal{name}
	{}

	std::string_view speak() const { return "Meaow"; }
};

class Dog : public Animal
{
public:
	Dog(std::string_view name)
		: Animal {name}
	{}

	std::string_view speak() const { return "Woof"; }
};

int main()
{
	const Cat cat{ "Fred" };
	std::cout << "cat is named " << cat.getName()//prints "Fred"
		<< ", and it says " << cat.speak() << '\n';//"Meow"

	const Dog dog{ "Garbo" };
	std::cout << "dog is named " << dog.getName()//"Garbo"
		<< ", and it says " << dog.speak() << '\n';//"Woof"

	const Animal* pAnimal{ &cat };
	std::cout << "pAnimal is named " << pAnimal->getName()//"Fred"
		<< ", and it says " << pAnimal->speak() << '\n';//"???"

	//now im going to switcher the pointer class to hold
	//the dog derived class instead

	pAnimal = &dog;
	std::cout << "pAnimal is named " << pAnimal->getName()//"Garbo"
		<< ", and it says " << pAnimal->speak() << '\n'; //"???"


	return 0;
}
