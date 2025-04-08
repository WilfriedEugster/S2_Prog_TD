#include "exercises.hpp"

#include "node.hpp"

#include <iostream>


void ex1(){
    std::cout << "Exercice 1 (Implémentation)" << std::endl;
    
    Node* root {create_node(5)};
    std::cout << "Creation racine : " << root->value << std::endl;

    std::vector<int> valeurs {3, 1, 4, 7, 6};
    std::cout << "Insertion des valeurs (dans l'ordre) : " << std::endl;
    for(auto x : valeurs){
        root->insert(x);
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "Hauteur de l'arbre : " << root->height() << std::endl;

    std::cout << "Affichage infixe : " << std::endl;
    root->display_infixe();
    std::cout << std::endl;

    std::cout << "Affichage prefixe : " << std::endl;
    std::vector<const Node*> vec {root->prefixe()};
    for(auto n : vec){
        std::cout << n->value << " ";
    }
    std::cout << std::endl;

    std::cout << "Valeur la plus a gauche : " << most_left(root)->value << std::endl;

    std::cout << "Suppresion des enfants de la racine" << std::endl;
    root->delete_childs();

    std::cout << "Affichage infixe : " << std::endl;
    root->display_infixe();
    std::cout << std::endl;
}

void ex2(){
    std::cout << "Exercice 2 (Utilisation)" << std::endl;

    
}