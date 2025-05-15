#pragma once

#include "Graph.hpp"
#include <iostream>


std::ostream& operator<<(std::ostream& os, Graph::WeightedGraphEdge const& edge);
std::ostream& operator<<(std::ostream& os, std::vector<Graph::WeightedGraphEdge> const& edges);
std::ostream& operator<<(std::ostream& os, Graph::WeightedGraph const& graph);
void test_display_graph(Graph::WeightedGraph const& graph);

void test_ex1();