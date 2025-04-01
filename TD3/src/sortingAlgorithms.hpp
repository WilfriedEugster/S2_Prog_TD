#pragma once

#include <vector>


// Exercice 1 (tri itératif)

void bubble_sort(std::vector<int> & vec);


// Exercice 2 (tri récursif)

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right, size_t const pivot);
void quick_sort(std::vector<int> & vec, size_t const left, size_t const right);
void quick_sort(std::vector<int> & vec);