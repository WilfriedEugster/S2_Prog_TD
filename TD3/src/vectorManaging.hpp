#pragma once

#include <vector>


bool is_sorted(std::vector<int> const& vec);
std::vector<int> generate_random_vector(size_t const size, int const max);
void swap(std::vector<int>& vec, size_t const i, size_t const j);
void display(std::vector<int> const& vec);