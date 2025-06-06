#pragma once

#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iostream>


bool is_integer(std::string const& s);

int first_word_length(std::string const& sentence);
std::vector<std::string> split_string(std::string const& str);

bool is_palindrome(std::string const& str);
void palindrome_test(std::string const& str);