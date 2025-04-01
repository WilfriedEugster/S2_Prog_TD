#include "sortingAlgorithms.hpp"
#include "vectorManaging.hpp"
#include "ScopedTimer.hpp"

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <optional>


int main()
{
    // Exercice 3 (Comparaison des algorithmes de tri)

    std::cout << "Exercice 3 (Comparaison des algorithmes de tri)" << std::endl;

    srand(std::time(0));

    int maximum_value {2000};
    std::vector<int> vec_original {generate_random_vector(1000, maximum_value)};
    std::vector<int> vec;

    std::cout << "Comparaison sur un vecteur de " << vec_original.size() << " éléments aléatoires entre 0 et " << maximum_value << std::endl;

    vec = vec_original;
    {
        ScopedTimer timer("Temps bubble_sort");
        bubble_sort(vec);
    }
    if (!is_sorted(vec)) std::cout << "LE TABLEAU N'EST PAS TRIE" << std::endl;

    vec = vec_original;
    {
        ScopedTimer timer("Temps quick_sort");
        quick_sort(vec);
    }
    if (!is_sorted(vec)) std::cout << "LE TABLEAU N'EST PAS TRIE" << std::endl;

    vec = vec_original;
    {
        ScopedTimer timer("Temps std::sort");
        std::sort(vec.begin(), vec.end());
    }
    if (!is_sorted(vec)) std::cout << "LE TABLEAU N'EST PAS TRIE" << std::endl;

    std::cout << std::endl;


    // Exercice 4 (dichotomie)

    std::cout << "Exercice 4 (dichotomie)" << std::endl;

    vec = {1, 2, 2, 3, 4, 8, 12};

    display_ex4({1, 2, 2, 3, 4, 8, 12}, 8);
    
    display_ex4({1, 2, 3, 3, 6, 14, 12, 15}, 15);
    display_ex4({2, 2, 3, 4, 5, 8, 12, 15, 16}, 16);
    display_ex4({5, 6, 7, 8, 9, 10, 11, 12, 13}, 6);
    display_ex4({1, 2, 3, 4, 5, 6, 7, 8, 9}, 10);


    return 0;
}