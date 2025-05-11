#pragma once

#include <string>


size_t folding_string_hash(std::string const& s, size_t max);
size_t folding_string_ordered_hash(std::string const& s, size_t max);
size_t polynomial_rolling_hash(std::string const& s, size_t p, size_t m);

void test_folding_string_hash(std::string const& s, size_t max);
void test_folding_string_ordered_hash(std::string const& s, size_t max);
void test_polynomial_rolling_hash(std::string const& s, size_t p, size_t m);

void test_ex1();