#include "exercises.hpp"

#include "given_code.hpp"
#include "utils.hpp"

#include <iostream>
#include <algorithm>
#include <numeric>


void ex1(){
    std::cout << "Exercice 1 (Vector and Algorithm)" << std::endl << std::endl;
    
    /*
    1. Remplir un std::vector avec des nombres entiers aléatoires compris entre 0 et 100.
    2. Utiliser les itérateurs et les méthodes begin et end pour afficher les valeurs du vecteur à l'aide d'une boucle for.
    3. Chercher si un nombre saisi par l'utilisateur est présent dans le vecteur à l'aide de la fonction std::find et afficher un message adapté.
    4. Utiliser la fonction std::count pour compter le nombre d'occurrences d'un nombre entier dans le vecteur. Vous pouvez trouver la documentation de la fonction std::count ici.
    5. Utiliser la fonction std::sort pour trier le vecteur.
    6. Utiliser la fonction std::accumulate pour calculer la somme des éléments du vecteur (par défaut, la fonction std::accumulate utilise l'opérateur + entre les éléments).
    */

    // 1.

    std::cout << "1. Remplissage du vecteur" << std::endl << std::endl;

    std::vector<int> vec = generate_random_vector(10, 10);
    
    // 2.

    std::cout << "2. Affichage du vecteur :" << std::endl;

    auto vec_end_iterator { vec.end() };
    for (auto it { vec.begin() }; it != vec_end_iterator; ++it)
        std::cout << *it << " ";

    std::cout << std::endl << std::endl;

    // 3.

    std::cout << "3. Saisissez un nombre entier : ";
    std::string number_string {};
    std::cin >> number_string;

    while (!is_integer(number_string)){
        std::cout << "Saisissez un NOMBRE ENTIER : ";
        std::cin >> number_string;
    }

    int number{std::stoi(number_string)};

    auto it {std::find(vec.begin(), vec_end_iterator, number)};
    if (it != vec.end())
    {
        std::cout << "L'élément " << *it << " a été trouvé." << std::endl << std::endl;
    }
    else
    {
        std::cout << "L'élément n'a pas été trouvé." << std::endl << std::endl;
    }

    // 4.

    std::cout << "4. Le nombre " << number << " apparaît " << std::count(vec.begin(), vec.end(), number) << " fois dans le vecteur." << std::endl << std::endl;

    // 5.

    std::cout << "5. Tri du vecteur" << std::endl;

    std::sort(vec.begin(), vec.end());

    std::cout << "Affichage du vecteur :" << std::endl;
    for (auto it {vec.begin()}; it != vec_end_iterator; ++it)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;

    // 6.

    std::cout << "6. Somme des éléments du vecteur : " << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;
}

void ex2(){
    std::cout << "Exercice 2 (String)" << std::endl;

    
}

void ex3(){
    std::cout << "Exercice 3 (Palindrome)" << std::endl;

    
}