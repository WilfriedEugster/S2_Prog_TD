#include "sortingAlgorithms.hpp"
#include "vectorManaging.hpp"

#include <iostream>
#include <vector>


int main()
{
    std::cout << "DEBUT" << std::endl;

    std::vector<int> array {generate_random_vector(10, 20)};

    display(array);

    quick_sort(array);

    display(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    std::cout << "FIN" << std::endl;
    return 0;
}