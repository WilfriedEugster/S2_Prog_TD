#include "functions.hpp"

#include <numeric>
#include <iostream>


// Exercice 1

size_t folding_string_hash(std::string const& s, size_t max){
    size_t sum {0};
    for(char c : s){
        sum = (sum + c) % max;
    }
    return sum;
}

void test_folding_string_hash(std::string const& s, size_t max){
    std::cout << "folding_string_hash(\"" << s << "\", " << max << ") --> " << folding_string_hash(s, max) << std::endl;
}

// Exercice 2



// Exercice 3

