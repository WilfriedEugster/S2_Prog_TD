
#include "exercises.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>


int main()
{
    std::cout << "DEBUT" << std::endl;

    std::srand(std::time(nullptr));

    //ex1();

    std::cout << std::endl;
    
    ex2();

    std::cout << std::endl;

    //ex3();
    
    std::cout << "FIN" << std::endl;
    return 0;
}