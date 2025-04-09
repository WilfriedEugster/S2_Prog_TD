#include "exercises.hpp"

#include "node.hpp"

#include <iostream>


void suppression(Node*& root, int value_to_remove){
    if (remove(root, value_to_remove))
        std::cout << "Suppression de " << value_to_remove << std::endl;
    else
        std::cout << "Impossible de supprimer " << value_to_remove << std::endl;
    std::cout << "Affichage infixe : ";
    root->display_infixe();
    std::cout << std::endl << std::endl;
}

void insertion_valeurs(Node*& root, std::vector<int> valeurs){
    std::cout << "Insertion des valeurs (dans l'ordre) : ";
    for(auto x : valeurs){
        root->insert(x);
        std::cout << x << " ";
    }
    std::cout << std::endl << std::endl;
}

void ex1(){
    std::cout << "Exercice 1 (Implémentation)" << std::endl << std::endl;
    
    Node* root {create_node(5)};
    std::cout << "Creation racine : " << root->value << std::endl;

    std::vector<int> valeurs {3, 1, 4, 11, 7, 6, 30, 8, 9, 29};
    insertion_valeurs(root, valeurs);

    std::cout << "Hauteur de l'arbre : " << root->height() << std::endl << std::endl;

    std::cout << "Affichage infixe : ";
    root->display_infixe();
    std::cout << std::endl;
    std::cout << "(Les * representent l'absence de fils)" << std::endl << std::endl;

    std::cout << "Affichage prefixe : ";
    std::vector<const Node*> vec {root->prefixe()};
    for(auto n : vec){
        std::cout << n->value << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Valeur la plus a gauche : " << most_left(root)->value << std::endl << std::endl;

    suppression(root, 1);
    suppression(root, 5);
    suppression(root, 7);
    suppression(root, 30);
    suppression(root, 18);

    std::cout << "Suppresion des enfants de la racine" << std::endl;
    root->delete_childs();

    std::cout << "Affichage infixe : " << std::endl;
    root->display_infixe();
    std::cout << std::endl << std::endl;

    insertion_valeurs(root, valeurs);
    std::cout << "Suppression de l'arbre" << std::endl;
    delete_tree(root);
}

void ex2(){
    std::cout << "Exercice 2 (Utilisation)" << std::endl;

    
}