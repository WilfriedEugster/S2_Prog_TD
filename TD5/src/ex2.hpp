#pragma once

#include <functional>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>


enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};

std::vector<std::pair<Insect, int>> get_insect_observations(size_t const number_of_observations, std::vector<float> const& insect_probabilities, unsigned int const seed);

std::vector<float> probabilities_from_count(std::vector<int> const& counts);

void test_ex2();