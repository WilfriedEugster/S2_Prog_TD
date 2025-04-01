#include "sortingAlgorithms.hpp"
#include "vectorManaging.hpp"

#include <vector>
#include <iostream>


// Exercice 1 (tri itératif)

bool bubbleSortStep(std::vector<int> & vec, size_t i){
    bool vecIsSorted {true};
    for (size_t j {0}; j < i; j++){
        if (vec[j] <= vec[j + 1])
            continue;
        swap(vec, j, j + 1);
        vecIsSorted = false;
    }
    return vecIsSorted;
}

void bubble_sort(std::vector<int> & vec){
    for (size_t i {vec.size() - 1}; i > 0; i--){
        bool vecIsSorted {bubbleSortStep(vec, i)};
        if (vecIsSorted)
            return;
    }
}


// Exercice 2 (tri récursif)

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right, size_t const pivot){
    swap(vec, pivot, right);
    size_t first_bigger_element {left};
    for (size_t i {left}; i < right; i++){
        if (vec[i] <= vec[right]){
            swap(vec, i, first_bigger_element);
            first_bigger_element++;
        }
    }
    swap(vec, right, first_bigger_element);
    return first_bigger_element;
}

void quick_sort(std::vector<int> & vec, size_t const left, size_t const right){
    if (!(left < right))
        return;

    size_t pivot = right;
    pivot = quick_sort_partition(vec, left, right, pivot);

    if (left < pivot)
        quick_sort(vec, left, pivot - 1);
    
    quick_sort(vec, pivot + 1, right);
}

void quick_sort(std::vector<int> & vec){
    quick_sort(vec, 0, vec.size() - 1);
}