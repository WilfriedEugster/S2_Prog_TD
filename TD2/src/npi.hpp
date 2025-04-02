#pragma once

#include <string>
#include <vector>


enum class Operator {ADD, SUB, MUL, DIV};
enum class TokenType {OPERATOR, OPERAND};
struct Token {
    TokenType type;
    float value;
    Operator op;
};


std::string entree();
bool is_floating(std::string const& s);
float npi_evaluate(std::vector<std::string> const& tokens);
float npi_evaluate(std::vector<std::string> const& tokens);
float operation_evaluate(float leftOperand, float rightOperand, std::string operator_symbol);

Token make_token(float value);
Token make_token(Operator op);
std::vector<Token> tokenize(std::vector<std::string> const& words);
Operator string_to_operator(std::string operator_symbol);
float npi_evaluate(std::vector<Token> const& tokens);
float operation_evaluate(float leftOperand, float rightOperand, Operator op);