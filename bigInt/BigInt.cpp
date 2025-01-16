#include <iostream>
#include <string>
#include "BigInt.h"
using namespace std;

BigInt::BigInt()
{
    negative = false;
    digits = "0";
}

BigInt::BigInt(int i)
{
    negative = (i >= 0) ? false : true;
    digits = (i >= 0) ? std::to_string(i) : std::to_string(-i);
}

BigInt::BigInt(string n)
{
    negative = (n.front() == '-') ? true: false;
    digits = (n.front() == '-') ? n.substr(1, n.size() - 1) : n;
}

string BigInt::to_string() const
{
    return (!negative) ? digits : "-" + digits;
}

bool BigInt::operator==(const BigInt& other) const {
    if ((digits == other.digits) && (negative == other.negative)){
	return true;
}
    return false;
}

bool BigInt::operator>(const BigInt& other) const {
    if (negative == false && other.negative == true) {
	return true;
}
    else if (negative == true && other.negative == false){
	return false;
}
    if (digits.length() > other.digits.length()){
	return true;
    }
    else if (negative == false && other.negative == false){
        for(int i = 0; i < digits.length(); i++){
	    if(digits[i] > other.digits[i]){
	        return true;
	    }
        }
    }
    else if (negative == true && other.negative == true){
        for(int i = 0; i < digits.length(); i++){
            if(digits[i] < other.digits[i]){
                return true;
            }
        }
    }
    return false;
}

bool BigInt::operator<(const BigInt& other) const {
    return !((this->operator==(other)) || (this->operator>(other)));
}

bool BigInt::operator!=(const BigInt& other) const {
    return !(this->operator==(other));
}

bool BigInt::operator>=(const BigInt& other) const {
    return ((this->operator==(other)) || (this->operator>(other)));
}

bool BigInt::operator<=(const BigInt& other) const {
    return ((this->operator==(other)) || (this->operator<(other)));
}

BigInt BigInt::operator+(const BigInt& other) const{
    char digsum, carry = 0;
    string sum = digits;

    for (int i = sum.size() - 1; i >= 0; i--) {
	digsum = (sum[i] - '0') + (other.digits[i] - '0');
	sum[i] = digsum % 10 + '0' + carry;
	carry = digsum > 9 ? 1 : 0;

    }
    if (carry != 0) {
	sum = carry + sum;
    }
    return BigInt(sum);
}

