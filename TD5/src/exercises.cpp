#include "exercises.hpp"

#include "given_code.hpp"
#include "functions.hpp"
#include <iostream>


void ex1(){
    std::cout << "Exercice 1 (Fonction de hachage)" << std::endl << std::endl;

    std::cout << "1." << std::endl;
    test_folding_string_hash("A", 200);
    test_folding_string_hash("AA", 200);
    test_folding_string_hash("AA", 100);
    test_folding_string_hash("Bonjour, je suis content d'etre ici avec vous.", 1000);
    std::cout << std::endl;

    std::cout << "2." << std::endl;
    test_folding_string_ordered_hash("A", 200);
    test_folding_string_ordered_hash("AA", 200);
    test_folding_string_ordered_hash("AA", 100);
    test_folding_string_ordered_hash("sqfgsd", 200);
    test_folding_string_ordered_hash("Bonjour, je suis content d'etre ici avec vous.", 1000);
    std::cout << std::endl;

    std::cout << "2." << std::endl;
    test_polynomial_rolling_hash("Ajhfkhvgv", 0, 1000);
    test_polynomial_rolling_hash("AA", 1, 1000);
    test_polynomial_rolling_hash("AA", 100, 10000);
    test_polynomial_rolling_hash("AA", 100, 1000);
    test_polynomial_rolling_hash("Bonjour, je suis content d'etre ici avec vous.", 31, 1e9 + 9);
    std::cout << std::endl;
}

void ex2(){
    std::cout << "Exercice 2 (Analyse du nombre d'insectes)" << std::endl << std::endl;
}

void ex3(){
    std::cout << "Exercice 3 (Hash sur une structure)" << std::endl << std::endl;
}