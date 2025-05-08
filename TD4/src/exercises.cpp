#include "exercises.hpp"

#include "given_code.hpp"
#include "functions.hpp"

#include <iostream>
#include <algorithm>
#include <numeric>


void ex1(){
    std::cout << "Exercice 1 (Vector and Algorithm)" << std::endl << std::endl;

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
    std::cout << "Exercice 2 (String)" << std::endl << std::endl;

    std::string sentence {"  Voici une    phrase "};

    std::cout << "1. Phrase : \"" << sentence << "\"" << std::endl;
    std::cout << "Taille du premier mot : " << first_word_length(sentence) << std::endl;
    std::cout << std::endl;

    std::cout << "2. Decoupage de la phrase en mots :" << std::endl;
    auto splitted_sentence {split_string(sentence)};
    for(auto word : splitted_sentence)
        std::cout << "\"" << word << "\"" << std::endl;
    std::cout << std::endl;
}

void ex3(){
    std::cout << "Exercice 3 (Palindrome)" << std::endl << std::endl;

    std::cout << "1." << std::endl;

    palindrome_test("ligysdflkfg");
    palindrome_test("kayak");
    palindrome_test("abcabc");
    palindrome_test("bonjourruojnob");
    palindrome_test("");

    std::cout << std::endl;
}