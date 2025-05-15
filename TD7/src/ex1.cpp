#include "ex1.hpp"

#include <algorithm>


// Exercice 1

void Graph::WeightedGraph::add_vertex(int const id){
    if (adjacency_list.find(id) != adjacency_list.end())
        return;
    adjacency_list[id] = {};
}

void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float const weight){
    add_vertex(from);
    add_vertex(to);

    std::vector<Graph::WeightedGraphEdge>* edges {&adjacency_list[from]};

    bool need_to_create_edge {true};
    for(std::size_t i {0}; i < (*edges).size(); i++)
        if (to == (*edges)[i].to){
            need_to_create_edge = false;
            (*edges)[i].weight = weight;
            break;
        }

    if (need_to_create_edge)
        (*edges).push_back(Graph::WeightedGraphEdge{to, weight});
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight){
    add_directed_edge(from, to, weight);
    add_directed_edge(to, from, weight);
}

Graph::WeightedGraph Graph::build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix){
    Graph::WeightedGraph graph{};
    
    for(std::size_t j {0}; j < adjacency_matrix.size(); j++){
        graph.add_vertex(j);
        std::vector<float> line{adjacency_matrix[j]};

        for(std::size_t i {0}; i < line.size(); i++)
            if (line[i] != 0.)
                graph.add_directed_edge(j, i, line[i]);
    }

    return graph;
}

// Tests

std::ostream& operator<<(std::ostream& os, Graph::WeightedGraphEdge const& edge){
    std::cout << edge.to << " (" << edge.weight << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, std::vector<Graph::WeightedGraphEdge> const& edges){
    for(Graph::WeightedGraphEdge edge : edges)
        std::cout << edge << "  ";
    return os;
}

std::ostream& operator<<(std::ostream& os, Graph::WeightedGraph const& graph){
    for(const auto& [vertex, edges] : graph.adjacency_list)
        std::cout << vertex << " : " << edges << std::endl;
    return os;
}

void test_add_vertexes(Graph::WeightedGraph& graph, std::vector<int> const& vertexes){
    std::cout << "Ajout des sommets :";
    for(int vertex : vertexes){
        std::cout << " " << vertex;
        graph.add_vertex(vertex);
    }
    std::cout << std::endl;
}

void test_display_graph(Graph::WeightedGraph const& graph){
    std::cout << "Affichage du graphe :" << std::endl;
    std::cout << graph << std::endl;
}

void test_ex1(){
    std::cout << "Exercice 1 (Fonction de hachage)" << std::endl << std::endl;


    std::cout << "1. Creation du graphe." << std::endl;
    Graph::WeightedGraph graph{};

    test_add_vertexes(graph, {0, 1});

    test_display_graph(graph);
    
    
    std::cout << "2. " << std::endl;

    std::vector<std::pair<std::pair<int, int>, float>> edges_data {{{0,1}, 1.},  {{1,2}, 1.},  {{0,1}, 1.},  {{1,0}, 2.3},  {{1,0}, 3.5},  {{3,0}, 0.75}};
    for(auto edge_data : edges_data){
        int from{edge_data.first.first};
        int to{edge_data.first.second};
        float weight{edge_data.second};

        std::cout << "Ajout de l'arrete de " << from << " vers " << to << " de poids " << weight << std::endl;
        graph.add_directed_edge(from, to, weight);
    }
    
    test_display_graph(graph);


    std::cout << "3. " << std::endl;

    std::vector<std::pair<std::pair<int, int>, float>> double_edges_data {{{2,3}, 13.3},  {{1,0}, 54.4}, {{4,0}, 107.7}};
    for(auto edge_data : double_edges_data){
        int from{edge_data.first.first};
        int to{edge_data.first.second};
        float weight{edge_data.second};
        
        std::cout << "Ajout de l'arrete double entre " << from << " et " << to << " de poids " << weight << std::endl;
        graph.add_undirected_edge(from, to, weight);
    }
    
    test_display_graph(graph);


    std::cout << "5." << std::endl;

    std::cout << "Creation d'un graphe a partir de la matrice :" << std::endl;
    std::vector<std::vector<float>> const& adjacency_matrix{
        {0, 1, 0, 0, 2},
        {0, 0, 2, 4, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0}
    };
    for(std::vector<float> line : adjacency_matrix){
        for(float weight : line)
            std::cout << weight << " ";
        std::cout << std::endl;
    }
    Graph::WeightedGraph graph_from_matrix {Graph::build_from_adjacency_matrix(adjacency_matrix)};
    test_display_graph(graph_from_matrix);

    std::cout << "Creation d'un graphe manuellement :" << std::endl;
    Graph::WeightedGraph homemade_graph {};
    test_add_vertexes(homemade_graph, {0, 1, 2, 3, 4});
    std::vector<std::pair<std::pair<int, int>, float>> homemade_edges_data {{{0,1}, 1.},  {{0,4}, 2.},  {{1,2}, 2.},  {{1,3}, 4.},  {{2,3}, 1.},  {{3,4}, 6.}};
    for(auto edge_data : homemade_edges_data){
        int from{edge_data.first.first};
        int to{edge_data.first.second};
        float weight{edge_data.second};

        std::cout << "Ajout de l'arrete de " << from << " vers " << to << " de poids " << weight << std::endl;
        homemade_graph.add_directed_edge(from, to, weight);
    }
    test_display_graph(homemade_graph);

    if (graph_from_matrix == homemade_graph)
        std::cout << "Les deux graphes sont egaux" << std::endl;
    else
        std::cout << "Les deux graphes sont differents" << std::endl;
}
