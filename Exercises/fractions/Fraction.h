#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Fraction {
    int numerator, denominator;
    Fraction(int n, int d);
    Fraction();
    Fraction(int i);
    Fraction(string s);

    string to_string();
    void print();

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

};

int gcd(int n, int d);
