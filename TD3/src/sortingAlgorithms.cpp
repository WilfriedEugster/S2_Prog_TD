#include "sortingAlgorithms.hpp"
#include "vectorManaging.hpp"

#include <vector>


// Exercice 1 (tri itératif)

bool bubbleSortStep(std::vector<int> & vec, size_t i){
    bool vecIsSorted {true};
    for (size_t j {0}; j < i; j++){
        if (vec[j] <= vec[j + 1])
            continue;
        swap(vec, j, j + 1);
        vecIsSorted = false;
    }
    return vecIsSorted;
}

void bubble_sort(std::vector<int> & vec){
    for (size_t i {vec.size() - 1}; i > 0; i--){
        bool vecIsSorted {bubbleSortStep(vec, i)};
        if (vecIsSorted)
            return;
    }
}

void selection_sort(std::vector<int> & vec){

}


// Exercice 2 (tri récursif)

/*
partitionner(tableau T, entier premier, entier dernier, entier pivot)
    échanger T[pivot] et T[dernier]  // échange le pivot avec le dernier du tableau , le pivot devient le dernier du tableau
    j := premier
    pour i de premier à dernier - 1 // la boucle se termine quand i = (dernier élément du tableau).
        si T[i] <= T[dernier] alors
            échanger T[i] et T[j]
            j := j + 1
    échanger T[dernier] et T[j]
    renvoyer j

tri_rapide(tableau T, entier premier, entier dernier)
        si premier < dernier alors
            pivot := choix_pivot(T, premier, dernier)
            pivot := partitionner(T, premier, dernier, pivot)
            tri_rapide(T, premier, pivot-1)
            tri_rapide(T, pivot+1, dernier)
*/

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right, size_t const pivot){
    swap(vec, pivot, right);
    size_t j {left};
    for (size_t i {left}; i < right; i++){
        if (vec[i] <= vec[right]){
            swap(vec, i, j);
            j++;
        }
    }
    swap(vec, right, j);
    return j;
}

void quick_sort(std::vector<int> & vec, size_t const left, size_t const right){
    if (!(left < right))
        return;

    size_t pivot = right;
    pivot = quick_sort_partition(vec, left, right, pivot);
    quick_sort(vec, left, pivot - 1);
    quick_sort(vec, pivot + 1, right);
}

void quick_sort(std::vector<int> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}