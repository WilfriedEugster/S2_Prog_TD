#pragma once

#include <iostream>
#include <vector>


enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;
    int hash() const;
};

std::vector<Card> get_cards(size_t const size);

bool operator==(Card const& a, Card const& b);

std::ostream& operator<<(std::ostream& os, CardKind const& ck);
std::ostream& operator<<(std::ostream& os, CardValue const& cv);
std::ostream& operator<<(std::ostream& os, Card const& c);
void test_cards_equality(Card const& a, Card const& b);
void test_card_hash(Card const& c);

void test_ex3();