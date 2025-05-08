#include "functions.hpp"

// Exercice 1

bool is_integer(std::string const& s){
    for(char current : s)
        if (!std::isdigit(current))
           return false;

    return true;
}

// Exercice 2

int first_word_length(std::string const& sentence){
    auto const is_space = [](char letter){ return letter == ' '; };
    auto first_word_begin = std::find_if_not(sentence.begin(), sentence.end(), is_space);
    auto first_space_it{std::find(first_word_begin, sentence.end(), ' ')};
    return std::distance(first_word_begin, first_space_it);
}

std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> output {};

    auto const is_space = [](char letter){ return letter == ' '; };

    auto str_end {str.end()};
    auto word_begin {str.begin()};
    auto word_end {str.begin()};

    while (word_begin != str_end){
        word_begin = std::find_if_not(word_end, str_end, is_space);
        word_end = std::find_if(word_begin, str_end, is_space);
        if (word_begin == str_end)
            break;
        std::string word = std::string(word_begin, word_end);
        output.push_back(word);
    }

    return output;
}

// Exercice 3

bool is_palindrome(std::string const& str){
    return std::equal(str.begin(), str.begin()+str.size()/2, str.rbegin(), str.rbegin()+str.size()/2);
}

void palindrome_test(std::string const& str){
    std::cout << "\"" << str << "\" ";
    
    if (is_palindrome(str))
        std::cout << "est";
    else
        std::cout << "n'est pas";

    std::cout << " un palindrome" << std::endl;
}