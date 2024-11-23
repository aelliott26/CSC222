#include "Time.h"
#include <iostream>
#include <string>

using namespace std;

Time::Time(int ss){
    s = ss;
}

Time::Time(int h, int m, int ss){
    s = ss + (m * 60) + (h * 3600);
}

Time::Time(int h, int m){
    s = h * 3600 + m * 60;
}

Time::Time(){
    s = 0;
}

Time Time::operator+(Time &t){
    return Time(t.s + this->s);
}

string Time::to_string(){
    return "no";
}
