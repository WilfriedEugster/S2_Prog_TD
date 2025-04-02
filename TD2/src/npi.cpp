#include "npi.hpp"

#include <iostream>
#include <string>
#include <cctype>


std::string entree(){
    std::string expression;
    std::cout << "Entrez une expression NPI : ";
    std::getline(std::cin, expression);
    return expression;
}

bool is_floating(std::string const& s){
    int number_of_dots {0};

    for(char current : s){
        if (std::isdigit(current))
           continue;

        if (current != '.')
            return false;
        
        number_of_dots++;
        if (number_of_dots > 1)
            return false;
    }

    return true;
}