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
	numerator = stoi (s.erase(slashpos));
	denominator = stoi (s2.erase(0,slashpos+1));
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

