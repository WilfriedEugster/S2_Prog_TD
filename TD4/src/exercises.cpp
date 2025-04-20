#include "exercises.hpp"

#include "given_code.hpp"

#include <iostream>


void ex1(){
    std::cout << "Exercice 1 (Vector and Algorithm)" << std::endl;
    
    /*
    1. Remplir un std::vector avec des nombres entiers aléatoires compris entre 0 et 100.
    2. Utiliser les itérateurs et les méthodes begin et end pour afficher les valeurs du vecteur à l'aide d'une boucle for.
    3. Chercher si un nombre saisi par l'utilisateur est présent dans le vecteur à l'aide de la fonction std::find et afficher un message adapté.
    4. Utiliser la fonction std::count pour compter le nombre d'occurrences d'un nombre entier dans le vecteur. Vous pouvez trouver la documentation de la fonction std::count ici.
    5. Utiliser la fonction std::sort pour trier le vecteur.
    6. Utiliser la fonction std::accumulate pour calculer la somme des éléments du vecteur (par défaut, la fonction std::accumulate utilise l'opérateur + entre les éléments).
    */
   
    std::cout << "1. Remplissage du vecteur" << std::endl;
    std::vector<int> vec = generate_random_vector(20, 100);
    
    std::cout << "2. Affichage du vecteur" << std::endl;
    auto vec_end_iterator { vec.end() };
    for (auto it { vec.begin() }; it != vec_end_iterator; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void ex2(){
    std::cout << "Exercice 2 (String)" << std::endl;

    
}

void ex3(){
    std::cout << "Exercice 3 (Palindrome)" << std::endl;

    
}