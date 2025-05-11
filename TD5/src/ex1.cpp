#include "ex1.hpp"

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

// Tests

void test_folding_string_hash(std::string const& s, size_t max){
    std::cout << "folding_string_hash(\"" << s << "\", " << max << ") --> " << folding_string_hash(s, max) << std::endl;
}

void test_folding_string_ordered_hash(std::string const& s, size_t max){
    std::cout << "folding_string_ordered_hash(\"" << s << "\", " << max << ") --> " << folding_string_ordered_hash(s, max) << std::endl;
}

void test_polynomial_rolling_hash(std::string const& s, size_t p, size_t m){
    std::cout << "polynomial_rolling_hash(\"" << s << "\", " << p << ", " << m << ") --> " << polynomial_rolling_hash(s, p, m) << std::endl;
}

void test_ex1(){
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

    std::cout << "3." << std::endl;
    test_polynomial_rolling_hash("Ajhfkhvgv", 0, 1000);
    test_polynomial_rolling_hash("AA", 1, 1000);
    test_polynomial_rolling_hash("AA", 100, 10000);
    test_polynomial_rolling_hash("AA", 100, 1000);
    test_polynomial_rolling_hash("Bonjour, je suis content d'etre ici avec vous.", 31, 1e9 + 9);
    std::cout << std::endl;
}
