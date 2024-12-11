#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Fraction {
    int numerator, denominator;
    Fraction(int n, int d);
    Fraction();
    Fraction(string s);

    string to_string();
    void print();

};