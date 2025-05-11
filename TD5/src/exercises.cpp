#include "exercises.hpp"

#include "given_code.hpp"
#include "functions.hpp"
#include <iostream>


void ex1(){
    std::cout << "Exercice 1 (Fonction de hachage)" << std::endl << std::endl;

    std::cout << "1." << std::endl;
    test_folding_string_hash("A", 200);
    test_folding_string_hash("AA", 200);
    test_folding_string_hash("sqfgsd", 200);
    test_folding_string_hash("Bonjour, je suis content d'etre ici avec vous.", 1000);
    test_folding_string_hash("jsqbgfjkvbfd;fshjvbd,:;,,", 5);
}

void ex2(){
    std::cout << "Exercice 2 (Analyse du nombre d'insectes)" << std::endl << std::endl;
}

void ex3(){
    std::cout << "Exercice 3 (Hash sur une structure)" << std::endl << std::endl;
}