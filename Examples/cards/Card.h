#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Suit {NONE, CLUBS, DIAMONDS, HEARTS, SPADES};
enum Rank {JOKER, TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
           NINE, TEN, JACK, QUEEN, KING, ACE};

struct Card
{
    Rank rank;
    Suit suit;
    Card();
    Card(Suit s, Rank r);
    std::string to_string() const;


    bool operator==(const Card&) const;
    bool operator>(const Card&) const;
    bool operator<(const Card&) const;
    bool operator>=(const Card&) const;
    bool operator<=(const Card&) const;
	bool operator!=(const Card&) const;
};
struct Deck {
    std::vector<Card> cards;

    Deck(int n);
    Deck();

    void print() const;
};

std::vector<Card> build_deck();
