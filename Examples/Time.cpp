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
    int m = s/60;
    int h = m/60;
    string sstring = ::to_string(s%60), mstring = ::to_string(m%60), hstring = ::to_string(h);
    if (sstring.length() == 1) sstring = "0" + sstring;
    if (mstring.length() == 1) mstring = "0" + mstring;   

    return hstring + ":" + mstring + ":" + sstring;
}
