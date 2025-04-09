#include "node.hpp"


#include <iostream>
#include <algorithm>


Node* create_node(int value){
    return new Node {value, nullptr, nullptr};
}

bool Node::is_leaf() const{
    return this->left == nullptr && this->right == nullptr;
}

void Node::insert(int value){
    if (value < this->value){
        if (left == nullptr)
            left = create_node(value);
        else
            left->insert(value);
    }
    else{
        if (right == nullptr)
            right = create_node(value);
        else
            right->insert(value);
    }
}

int node_height(Node* const n){
    if (n == nullptr)
        return 0;
    
    return n->height();
}

int Node::height() const{
    return std::max(node_height(left), node_height(right)) + 1;
}

void node_delete_childs(Node* n){
    if (n != nullptr){
        n->delete_childs();
        delete n;
    }
}

void Node::delete_childs(){
    node_delete_childs(left);
    left = nullptr;
    node_delete_childs(right);
    right = nullptr;
}

void node_display_infixe(Node* const n){
    if (n == nullptr){
        std::cout << "*";
        return;
    }
    
    std::cout << "(";
    n->display_infixe();
    std::cout << ")";
}

void Node::display_infixe() const{
    node_display_infixe(left);
    std::cout << " " << value << " ";
    node_display_infixe(right);
}

std::vector<Node const*> node_prefixe(Node* const n){
    if (n == nullptr)
        return {};
    
    return n->prefixe();
}

std::vector<Node const*> Node::prefixe() const{
    std::vector<Node const*> output {this};

    auto left_nodes {node_prefixe(left)};
    output.insert(output.end(), left_nodes.begin(), left_nodes.end());

    auto right_nodes {node_prefixe(right)};
    output.insert(output.end(), right_nodes.begin(), right_nodes.end());

    return output;
}

Node*& most_left(Node*& node){
    if (node->left == nullptr)
        return node;
        
    return most_left(node->left);
}

void remove_node(Node*& node){
    if (node->is_leaf()){
        delete node;
        node = nullptr;
        return;
    }

    if (node->left == nullptr){
        Node* node2 = node;
        node = node->right;
        delete node2;
        return;
    }

    if (node->right == nullptr){
        Node* node2 = node;
        node = node->left;
        delete node2;
        return;
    }

    Node* next_descendant = most_left(node->right);
    node->value = next_descendant->value;
    remove(node->right, next_descendant->value);
}

bool remove(Node*& node, int value){
    if (node == nullptr)
        return false;

    if (node->value == value){
        remove_node(node);
        return true;
    }

    if (value < node->value)
        return remove(node->left, value);
    else
        return remove(node->right, value);
}

void delete_tree(Node* node){
    node->delete_childs();
    delete node;
}