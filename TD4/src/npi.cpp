#include "npi.hpp"

#include <iostream>
#include <string>
#include <cctype>
#include <stack>


std::string entree(){
    std::string expression;
    std::cout << "Entrez une expression NPI : ";
    std::getline(std::cin, expression);
    return expression;
}

bool is_floating(std::string const& s){
    int number_of_dots {0};

    for(char current : s){
        if (std::isdigit(current))
           continue;

        if (current != '.')
            return false;
        
        number_of_dots++;
        if (number_of_dots > 1)
            return false;
    }

    return true;
}

float npi_evaluate(std::vector<std::string> const& tokens){
    std::stack<float> stack;

    for(std::string t : tokens){
        if (is_floating(t)){
            stack.push(std::stof(t));
            continue;
        }

        float rightOperand{stack.top()};
        stack.pop();
        float leftOperand{stack.top()};
        stack.pop();

        stack.push(operation_evaluate(leftOperand, rightOperand, t));
    }
    
    return stack.top();
}

float operation_evaluate(float leftOperand, float rightOperand, std::string operator_symbol){
    if (operator_symbol == "+")
        return leftOperand + rightOperand;

    if (operator_symbol == "-")
        return leftOperand - rightOperand;

    if (operator_symbol == "*")
        return leftOperand * rightOperand;

    if (operator_symbol == "/")
        return leftOperand / rightOperand;
    
    return 0;
}


Token make_token(float value){
    Token new_token {TokenType::OPERAND, value, Operator::ADD};
    return new_token;
}

Token make_token(Operator op){
    Token new_token {TokenType::OPERATOR, 0., op};
    return new_token;
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> tokens{};
    
    for(std::string w : words){
        Token t;

        if (is_floating(w))
            t = make_token(std::stof(w));
        else
            t = make_token(string_to_operator(w));

        tokens.push_back(t);
    }

    return tokens;
}

Operator string_to_operator(std::string operator_symbol){
    if (operator_symbol == "+")
        return Operator::ADD;

    if (operator_symbol == "-")
        return Operator::SUB;

    if (operator_symbol == "*")
        return Operator::MUL;

    if (operator_symbol == "/")
        return Operator::DIV;
    
    return Operator::ADD;
}

float npi_evaluate(std::vector<Token> const& tokens){
    std::stack<float> stack;

    for(Token t : tokens){
        if (t.type == TokenType::OPERAND){
            stack.push(t.value);
            continue;
        }

        float rightOperand{stack.top()};
        stack.pop();
        float leftOperand{stack.top()};
        stack.pop();

        stack.push(operation_evaluate(leftOperand, rightOperand, t.op));
    }
    
    return stack.top();
}

float operation_evaluate(float leftOperand, float rightOperand, Operator op){
    if (op == Operator::ADD)
        return leftOperand + rightOperand;

    if (op == Operator::SUB)
        return leftOperand - rightOperand;

    if (op == Operator::MUL)
        return leftOperand * rightOperand;

    if (op == Operator::DIV)
        return leftOperand / rightOperand;
    
    return 0;
}