#include <string>
using namespace std;

string increment_digit_string(const string &);
string sum_common_len_digit_strs(const string&, const string&);
string sub_common_len_digit_strs(const string&, const string&);


class BigInt
{
    bool negative;
    string digits;

    public:
    // constructors
    BigInt();
    BigInt(int);
    BigInt(string);

    // member functions
    string to_string() const;
    bool operator==(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator<(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;

};
