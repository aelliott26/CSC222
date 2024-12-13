#include <iostream>
#include "Fraction.h"
using namespace std;

Fraction::Fraction(int n, int d) {
	numerator = n;
	denominator = d;
	int gcf = gcd(numerator, denominator);
	numerator /= gcf;
	denominator /= gcf;
}


Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int i) {
        numerator = i;
        denominator = 1;
}

Fraction::Fraction(string s) {
	string slash = "/", s2 = s;
	int slashpos = s.find(slash);
	if (slashpos > 0){
		numerator = stoi (s.erase(slashpos));
		denominator = stoi (s2.erase(0,slashpos+1));
}
	if (slashpos < 0){
		numerator = stoi (s);
		denominator = 1;
}
}

string Fraction::to_string(){
	if (numerator/denominator){
		return ::to_string(numerator/denominator);
}
	return ::to_string(numerator) + "/" + ::to_string(denominator);
}

int gcd(int n, int d) {
    if (n == 0)
        return d;
    return gcd(d % n, n);
}

bool Fraction::operator==(const Fraction& other) const {
if (numerator == other.numerator && denominator == other.denominator) {
	return true;
}
    return false;
}

bool Fraction::operator!=(const Fraction& other) const {
if (numerator != other.numerator && denominator != other.denominator) {
        return true;
}
    return false;
}

bool Fraction::operator<(const Fraction& other) const {
	double n1 = numerator;
	double d1 = denominator;
        double n2 = other.numerator;
        double d2 = other.denominator;

if (n1/d1 < n2/d2) {
        return true;
}
    return false;
}

bool Fraction::operator<=(const Fraction& other) const {
        double n1 = numerator;
        double d1 = denominator;
        double n2 = other.numerator;
        double d2 = other.denominator;
if (numerator == other.numerator && denominator == other.denominator) {
        return true;
}
if (n1/d1 < n2/d2) {
        return true;
}
    return false;
}

bool Fraction::operator>(const Fraction& other) const {
        double n1 = numerator;
        double d1 = denominator;
        double n2 = other.numerator;
        double d2 = other.denominator;
if (n1/d1 > n2/d2) {
        return true;
}
    return false;
}

bool Fraction::operator>=(const Fraction& other) const {
        double n1 = numerator;
        double d1 = denominator;
        double n2 = other.numerator;
        double d2 = other.denominator;
if (numerator == other.numerator && denominator == other.denominator) {
        return true;
}
if (n1/d1 > n2/d2) {
        return true;
}
    return false;
}



