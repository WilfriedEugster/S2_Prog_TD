#pragma once

#include <vector>
#include <optional>


bool is_sorted(std::vector<int> const& vec);
std::vector<int> generate_random_vector(size_t const size, int const max);
void swap(std::vector<int>& vec, size_t const i, size_t const j);
void display(std::vector<int> const& vec);

std::optional<size_t> search(std::vector<int> const& vec, int val, size_t left, size_t right);
std::optional<size_t> search(std::vector<int> const& vec, int val);

void display_ex4(std::vector<int> const& vec, int val);