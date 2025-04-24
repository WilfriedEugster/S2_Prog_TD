#include "utils.hpp"

bool is_integer(std::string const& s){
    for(char current : s)
        if (!std::isdigit(current))
           return false;

    return true;
}