#include <iostream>
#include <string>
#include "BigInt.h"
#define to_num(c) (c-'0')
#define digit_to_char(d) (d+'0')
using namespace std;

string increment_digit_string(const string &digit_string)
{
    string digits = digit_string;
    int pos = digits.size() - 1;
    char next_digit = digits[pos] + 1;

    while (next_digit > '9' && pos >= 0) {
        digits[pos] = '0';
        next_digit = digits[--pos] + 1;
    }

    if (pos >= 0)
        digits[pos] = next_digit;
    else
        digits = "1" + digits;

    return digits;
}

string sum_common_len_digit_strs(const string &s1, const string &s2)
{
    char digit_sum, carry = 0;
    string sum = s1;

    for (int i = s1.size() - 1; i >= 0; i--) {
        digit_sum = to_num(s1[i]) + to_num(s2[i]) + carry;
        sum[i] = digit_to_char(digit_sum % 10);
        carry = digit_sum > 9 ? 1 : 0;
    }

    return carry ? "c+" + sum : sum;
}

string sub_common_len_digit_strs(const string &s1, const string &s2)
{
    string results, s3, s4;
    if (s1[0] == '-') {
        s3 = s1.substr(1, s1.size());
        results = sum_common_len_digit_strs(s3, s2);
        return "-" + results;
}
    if (s2[0] == '-') {
        s4 = s2.substr(1, s2.size());
        results = sum_common_len_digit_strs(s4, s1);
        return  results;
} 

    bool negative = s1 < s2;
    const string &larger = negative ? s2 : s1;
    const string &smaller = negative ? s1 : s2;

    string result(larger.size(), 0);
    char borrow = 0;  
        
    for (int i = s1.size() - 1; i >= 0; --i) {  
        int digit1 = to_num(larger[i]) - borrow;  
        int digit2 = i >= larger.size() - smaller.size() ? to_num(smaller[i - (larger.size() - smaller.size())]) : 0;

        if (digit1 < digit2) { 
            digit1 += 10;  
            borrow = 1;   
        } else {  
            borrow = 0;  
        }    
        result[i] = digit_to_char(digit1 - digit2);  
    }  

    size_t pos = result.find_first_not_of('0');  
    if (pos != string::npos) {  
        result =  result.substr(pos);  
    }  else {
        return "0";  
}
    return negative ? "-" + result : result;
}

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
    if ((*this).digits.size() == other.digits.size()) {
        string raw_sum = sum_common_len_digit_strs((*this).digits, other.digits);
        if (raw_sum[0] == 'c')
            return BigInt("1" + raw_sum.substr(2));
        return BigInt(raw_sum);
    }
        
    // Addends have different numbers of digits
    const BigInt *longer;
    const BigInt *shorter;
    int common, extra;
    string summed_common_digits, leading_digits;

    if ((*this).digits.size() > other.digits.size()) {
        longer = this;
        shorter = &other;
    } else {
        longer = &other;
        shorter = this;
    };

    common = shorter->digits.size();
    extra = longer->digits.size() - common;
    summed_common_digits = sum_common_len_digit_strs(
       shorter->digits, 
       longer->digits.substr(extra)
    );
    leading_digits = longer->digits.substr(0, extra);

    if (summed_common_digits[0] != 'c')
        return BigInt(leading_digits + summed_common_digits);

    return BigInt(increment_digit_string(leading_digits) +
                  summed_common_digits.substr(2));
}

BigInt BigInt::operator-(const BigInt& other) const {
    if (this->negative != other.negative) {
        BigInt temp = other;
        temp.negative = !other.negative;
        return *this + temp;
    }

    if (*this < other) {
        BigInt result = other - *this;
        result.negative = !this->negative;
        return result;
    }

    string result(digits.size(), '0');
    char borrow = 0;
    int this_len = digits.size(), other_len = other.digits.size();

    for (int i = 0; i < this_len; ++i) {
        int digit1 = to_num(digits[this_len - 1 - i]) - borrow;
        int digit2 = (i < other_len) ? to_num(other.digits[other_len - 1 - i]) : 0;

        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result[this_len - 1 - i] = digit_to_char(digit1 - digit2);
    }

    size_t pos = result.find_first_not_of('0');
    if (pos != string::npos) {
        result = result.substr(pos);
    } else {
        result = "0";
    }

    return BigInt(this->negative ? "-" + result : result);
}

BigInt BigInt::operator*(const BigInt& other) const {
    return BigInt("0");
}
