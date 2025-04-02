#include "given_code.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <iterator>


std::vector<std::string> split_string(std::string const& s){
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}