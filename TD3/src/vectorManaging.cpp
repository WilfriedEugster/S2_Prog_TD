#include "vectorManaging.hpp"

#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>


bool is_sorted(std::vector<int> const& vec){ 
    return std::is_sorted(vec.begin(), vec.end()); 
}

std::vector<int> generate_random_vector(size_t const size, int const max = 100){
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

void swap(std::vector<int>& vec, size_t const i, size_t const j){
    std::cout << "swap " << i << " " << j << std::endl;
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

void display(std::vector<int> const& vec){
    for(int element : vec){
        std::cout << element << " ";
    }
    std::cout << std::endl;
}