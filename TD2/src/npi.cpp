#include "npi.hpp"

#include <iostream>
#include <string>


std::string entree(){
    std::string expression;
    std::cout << "Entrez une expression NPI : ";
    std::getline(std::cin, expression);
    return expression;
}