#pragma once

#include <vector>


struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_childs();
    void display_infixe() const;
    std::vector<Node const*> prefixe() const;
};


Node* create_node(int value);
int node_height(Node const* n);
std::vector<Node const*> node_prefixe(Node* const n);
Node*& most_left(Node*& node);
bool remove(Node*& node, int value);
void delete_tree(Node* node);