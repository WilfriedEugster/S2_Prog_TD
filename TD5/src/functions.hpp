#pragma once
#include <string>


size_t folding_string_hash(std::string const& s, size_t max);
void test_folding_string_hash(std::string const& s, size_t max);