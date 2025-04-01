#include "exercises.hpp"

#include "npi.hpp"
#include "given_code.hpp"

#include <iostream>
#include <string>


void ex1(){
    std::cout << "Exercice 1 (Evaluation NPI)" << std::endl;

    std::string input = entree();
    std::vector<std::string> vec = split_string(input);
    for(std::string s : vec)
        std::cout << s << std::endl;
    
}

void ex2(){
    std::cout << "Exercice 2 (Utiliser une structure et des énumérations)" << std::endl;
}