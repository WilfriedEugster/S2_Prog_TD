#include "ex3.hpp"

#include <string>
#include <unordered_map>


namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

// Exercice 2

bool operator==(Card const& a, Card const& b){
    return a.kind == b.kind && a.value == b.value;
}

int Card::hash() const{
    return (static_cast<int>(this->value) * 4 + static_cast<int>(this->kind)) % 52;
}

// Tests

std::ostream& operator<<(std::ostream& os, CardKind const& ck){
    std::unordered_map<CardKind, std::string> const card_kind_to_string = {
        {CardKind::Heart, "Heart"},
        {CardKind::Diamond, "Diamond"},
        {CardKind::Club, "Club"},
        {CardKind::Spade, "Spade"}
    };
    return os << card_kind_to_string.at(ck);
}

std::ostream& operator<<(std::ostream& os, CardValue const& cv){
    std::unordered_map<CardValue, std::string> const card_value_to_string = {
        {CardValue::Two, "Two"},
        {CardValue::Three, "Three"},
        {CardValue::Four, "Four"},
        {CardValue::Five, "Five"},
        {CardValue::Six, "Six"},
        {CardValue::Seven, "Seven"},
        {CardValue::Eight, "Eight"},
        {CardValue::Nine, "Nine"},
        {CardValue::Ten, "Ten"},
        {CardValue::Jack, "Jack"},
        {CardValue::Queen, "Queen"},
        {CardValue::King, "King"},
        {CardValue::Ace, "Ace"}
    };
    return os << card_value_to_string.at(cv);
}

std::ostream& operator<<(std::ostream& os, Card const& c){
    return os << c.value << " of " << c.kind;
}

void test_cards_equality(Card const& a, Card const& b){
    std::cout << a << " == " << b << " --> " << ((a == b) ? "True" : "False") << std::endl;
}

void test_card_hash(Card const& c){
    std::cout << c.hash() << ", ";
}

void test_ex3(){
    std::cout << "Exercice 3 (Hash sur une structure)" << std::endl << std::endl;

    std::cout << "1. Tests d'egalite :" << std::endl;
    test_cards_equality(Card{CardKind::Heart, CardValue::Ace}, Card{CardKind::Heart, CardValue::Ace});
    test_cards_equality(Card{CardKind::Club, CardValue::Ace}, Card{CardKind::Heart, CardValue::Ace});
    test_cards_equality(Card{CardKind::Heart, CardValue::Ace}, Card{CardKind::Heart, CardValue::King});
    test_cards_equality(Card{CardKind::Diamond, CardValue::Five}, Card{CardKind::Heart, CardValue::Ace});
    std::cout << std::endl;

    std::cout << "3. Calculs de tous les hash possibles (1 pour chaque carte possible) :" << std::endl;
    std::vector<CardValue> cards_values {CardValue::Two, CardValue::Three, CardValue::Four, CardValue::Five, CardValue::Six, CardValue::Seven, CardValue::Eight, CardValue::Nine, CardValue::Ten, CardValue::Jack, CardValue::Queen, CardValue::King, CardValue::Ace};
    std::vector<CardKind> cards_kinds {CardKind::Heart, CardKind::Diamond, CardKind::Club, CardKind::Spade};
    std::vector<Card> all_cards {};
    for(CardValue cv : cards_values)
        for(CardKind cd : cards_kinds)
            all_cards.push_back(Card{cd, cv});

    for(Card c : all_cards){
        test_card_hash(c);
    }
    std::cout << std::endl << std::endl;

    std::cout << "4. Génération de 100 cartes aleatoires. Affichage du nombre d'exemplaires de chaque carte possible :" << std::endl;
    std::unordered_map<Card, int> card_to_count;
    std::vector<Card> card_sample {get_cards(100)};
    for(Card c : all_cards){
        card_to_count[c] = 0;
    }
    for(Card c : card_sample){
        card_to_count[c]++;
    }
    for(Card c : all_cards){
        std::cout << c << " : " << card_to_count[c] << std::endl;
    }
}
