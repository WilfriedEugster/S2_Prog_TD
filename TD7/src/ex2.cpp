#include "ex2.hpp"

#include <iostream>
#include <unordered_map>
#include <string>
#include <numeric>
#include <cmath>


std::vector<Insect> const insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
};

std::unordered_map<Insect, std::string> const insect_to_string = {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}
};

std::vector<int> const expected_insect_counts {
    75, // ClassicBee
    50, // Ladybug
    100, // Butterfly
    20, // Dragonfly
    400, // Ant
    150, // Grasshopper
    60, // Beetle
    10, // Wasp
    40, // Caterpillar
    90, // Spider 
    5, // GuimielBee
};

std::vector<std::pair<Insect, int>> get_insect_observations(size_t const number_of_observations, std::vector<float> const& insect_probabilities, unsigned int const seed = std::random_device{}()) {
    // Create a random engine with a given seed
    std::default_random_engine random_engine{seed};

    auto rand_insect_index { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { rand_insect_index() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        // If we have already seen the same insect, increment the count on the last observation
        if(!observations.empty() && observations.back().first == random_insect) {
            observations.back().second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

// Exercice 2

std::vector<float> probabilities_from_count(std::vector<int> const& counts){
    float counts_sum = static_cast<float>(std::accumulate(counts.begin(), counts.end(), 0));
    std::vector<float> res {};
    for(int count : counts){
        res.push_back(count / counts_sum);
    }
    return res;
}

// Tests

void test_ex2(){
    std::cout << "Exercice 2 (Analyse du nombre d'insectes)" << std::endl << std::endl;


    std::cout << "1. Probabilites attendues des insectes :" << std::endl;

    auto expected_insect_probabilities {probabilities_from_count(expected_insect_counts)};

    for(size_t i {0}; i < insect_values.size(); i++){
        std::string insect_name {insect_to_string.at(insect_values[i])};
        float insect_probability {expected_insect_probabilities[i]};
        std::cout << insect_probability << " : " << insect_name << std::endl;
    }

    std::cout << std::endl;
    

    std::cout << "2. Observations generees :" << std::endl;

    std::vector<std::pair<Insect, int>> insect_count_pairs {get_insect_observations(1000, expected_insect_probabilities)};
    std::unordered_map<Insect, int> insect_to_count {};

    for(Insect insect : insect_values)
        insect_to_count[insect] = 0;

    for(auto insect_count_pair : insect_count_pairs){
        Insect insect {insect_count_pair.first};
        int number {insect_count_pair.second};
        insect_to_count[insect] += number;
    }
    
    for(Insect insect : insect_values){
        std::string insect_name {insect_to_string.at(insect)};
        int insect_count {insect_to_count[insect]};
        std::cout << insect_count << " : " << insect_name << std::endl;
    }

    std::cout << std::endl;


    std::cout << "3. Conversion du resultat en vecteur de comptage. Calcul des probabilites." << std::endl;

    std::vector<int> observed_insect_counts {};

    for(Insect insect : insect_values){
        int insect_count {insect_to_count[insect]};
        observed_insect_counts.push_back(insect_count);
    }

    auto observed_insect_probabilities {probabilities_from_count(observed_insect_counts)};

    std::cout << std::endl;

    
    std::cout << "4. Probabilites des insectes observes vs probabilites attendues :" << std::endl;

    for(size_t i {0}; i < insect_values.size(); i++){
        Insect insect {insect_values[i]};
        std::string insect_name {insect_to_string.at(insect)};

        float observed_probability {observed_insect_probabilities[i]};
        float expected_probability {expected_insect_probabilities[i]};

        float difference {observed_probability - expected_probability};
        bool difference_is_small_enough {std::abs(difference) < 0.01};
        std::string comment {(difference_is_small_enough) ? "OK" : "BAD"};

        std::cout << insect_name << " : " << observed_probability << " vs " << expected_probability << " " << comment << std::endl;
    }

    std::cout << std::endl;
}
