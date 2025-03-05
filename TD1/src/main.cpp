#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1{3, 4};
    Fraction f2{1, 2};

    std::cout << "f1 = " << f1 << " f2 = " << f2 << std::endl;

    std::cout << "add(f1, f2) = " << add(f1, f2) << std::endl;
    std::cout << "sub(f1, f2) = " << sub(f1, f2) << std::endl;
    std::cout << "mul(f1, f2) = " << mul(f1, f2) << std::endl;
    std::cout << "div(f1, f2) = " << div(f1, f2) << std::endl;

    std::cout << "Exercice 1" << std::endl;

    std::cout << "f1 + f2 = " << f1 + f2 << std::endl;
    std::cout << "f1 - f2 = " << f1 - f2 << std::endl;
    std::cout << "f1 * f2 = " << f1 * f2 << std::endl;
    std::cout << "f1 / f2 = " << f1 / f2 << std::endl;

    std::cout << "Exercice 3" << std::endl;

    std::cout << "f1 == 6/8 = " << (f1 == Fraction{6, 8}) << std::endl;
    std::cout << "f1 == f2 = " << (f1 == f2) << std::endl;
    std::cout << "10/20 != f2 = " << (Fraction{10, 20} != f2) << std::endl;
    std::cout << "f1 != f2 = " << (f1 != f2) << std::endl;


    return 0;
}