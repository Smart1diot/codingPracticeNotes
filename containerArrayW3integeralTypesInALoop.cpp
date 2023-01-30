#include <iostream>
#include <string>

struct Container
{
    std::string name{};
    int age{};
    double wage{};
};

Container swag[3]{};

int main()
{
    swag[0].name = { "Ben Jerry." };
    swag[1].age = { 21 };
    swag[2].wage = { 25.26 };

    for (swag[1].age; swag[1].age <= 23; swag[1].age++) // Maybe a year of times is going by for three years changing the gentlements age up a year each loop
    {
        std::cout << "Name: " << swag[0].name << '\n';
        std::cout << "Age: " << swag[1].age << '\n';
        std::cout << "wage: " << swag[2].wage << '\n' << '\n';
    }

    std::cout << "It appears we have reached the end of the loop and thus the end of the code itself, god bless our souls" << '\n';

    return 0;
}
