#pragma once

#include <iostream>

struct Fraction
{
    int numerator{0};
    int denominator{1};

    void display();
};

Fraction add(Fraction const &f1, Fraction const &f2);
Fraction sub(Fraction const &f1, Fraction const &f2);
Fraction mul(Fraction const &f1, Fraction const &f2);
Fraction div(Fraction const &f1, Fraction const &f2);

// Exercice 1

Fraction operator+(Fraction const &f1, Fraction const &f2);
Fraction operator-(Fraction const &f1, Fraction const &f2);
Fraction operator*(Fraction const &f1, Fraction const &f2);
Fraction operator/(Fraction const &f1, Fraction const &f2);

// Exercice 2

std::ostream &operator<<(std::ostream &os, Fraction const &f);

// Exercice 3

bool operator==(Fraction const &f1, Fraction const &f2);
bool operator!=(Fraction const &f1, Fraction const &f2);

// Exercice 4

bool operator<(Fraction const &f1, Fraction const &f2);
bool operator<=(Fraction const &f1, Fraction const &f2);
bool operator>(Fraction const &f1, Fraction const &f2);
bool operator>=(Fraction const &f1, Fraction const &f2);