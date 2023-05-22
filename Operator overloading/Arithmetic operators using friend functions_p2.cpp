#include <iostream>

class Fraction
{
private:
	int numerator{ 0 };
	int denominator{ 1 };

public:
	Fraction(int numerator, int denominator = 1)
		: numerator{ numerator }, denominator{ denominator } {}

	void print() const
	{
		std::cout << numerator << '/' << denominator << '\n';
	}

	friend Fraction operator*(Fraction& class1, Fraction& class2);
	friend Fraction operator*(Fraction& classs, int num);
	friend Fraction operator*(int num, Fraction& classs);
};

Fraction operator*(Fraction& class1, Fraction& class2)
{
	return { class1.numerator * class2.numerator, class1.denominator * class2.denominator };
}

Fraction operator*(Fraction& class1, int num) // 2 = 2/1
{
	return { class1.numerator * num, class1.denominator};
}

Fraction operator*(int num, Fraction& classs) // 2 = 2/1
{
	return classs * num;
}

int main()
{
	Fraction f1{ 2,5 };
	Fraction f2{ 3,8 };
	Fraction f3{ f1 * f2 };
	Fraction f4{ f1 * 2 }; // 2 = 2/1
	Fraction f5{ 2 * f2 }; // 2 = 2/1

	f1.print();
	f2.print();
	f3.print();
	f4.print();
	f5.print();

	return 0;
}
