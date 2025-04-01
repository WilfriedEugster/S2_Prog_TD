#include "vectorManaging.hpp"

#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <optional>


bool is_sorted(std::vector<int> const& vec){ 
    return std::is_sorted(vec.begin(), vec.end()); 
}

std::vector<int> generate_random_vector(size_t const size, int const max = 100){
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

void swap(std::vector<int>& vec, size_t const i, size_t const j){
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

// Exercice 4

std::optional<size_t> search(std::vector<int> const& vec, int val, size_t left, size_t right){
    if (right < left)
        return std::nullopt;

    size_t middle {(left + right) / 2};
    
    if (vec[middle] == val)
        return middle;

    if (vec[middle] < val)
        return search(vec, val, middle + 1, right);
    
    if (val < vec[middle]){
        if (middle > 0)
            return search(vec, val, left, middle - 1);
        else
            return std::nullopt;
    }
}

std::optional<size_t> search(std::vector<int> const& vec, int val){
    return search(vec, val, 0, vec.size() - 1);
}

void display_ex4(std::vector<int> const& vec, int val){
    std::optional<size_t> index = search(vec, val);

    std::cout << "vec = ";
    display(vec);

    if (!index.has_value()){
        std::cout << val << " non trouvé" << std::endl;
        return;
    }
    
    std::cout << "vec[" << index.value() << "] = " << val << std::endl;
}