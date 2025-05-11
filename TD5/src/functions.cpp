#include "functions.hpp"

#include <numeric>
#include <iostream>


// Exercice 1

size_t folding_string_hash(std::string const& s, size_t max){
    size_t sum {0};

    for(char character : s){
        sum = (sum + character) % max;
    }

    return sum;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t sum {0};
    size_t coefficient {1};

    for(char character : s){
        sum = (sum + character * coefficient) % max;
        coefficient++;
    }

    return sum;
}

size_t polynomial_rolling_hash(std::string const& s, size_t p, size_t m){
    size_t sum {0};
    size_t power {1};

    for(char character : s){
        sum = (sum + character * power) % m;
        power *= p;
    }

    return sum;
}

// Tests exercice 1

void test_folding_string_hash(std::string const& s, size_t max){
    std::cout << "folding_string_hash(\"" << s << "\", " << max << ") --> " << folding_string_hash(s, max) << std::endl;
}

void test_folding_string_ordered_hash(std::string const& s, size_t max){
    std::cout << "folding_string_ordered_hash(\"" << s << "\", " << max << ") --> " << folding_string_ordered_hash(s, max) << std::endl;
}

void test_polynomial_rolling_hash(std::string const& s, size_t p, size_t m){
    std::cout << "polynomial_rolling_hash(\"" << s << "\", " << p << ", " << m << ") --> " << polynomial_rolling_hash(s, p, m) << std::endl;
}

// Exercice 2



// Exercice 3

