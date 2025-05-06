#include "given_code.hpp"

#include <cstdlib>
#include <algorithm>


std::vector<int> generate_random_vector(size_t const size, int const max = 100){
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

