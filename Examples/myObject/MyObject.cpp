#include "MyObject.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> MyObject::specdays = {{},{},{},{},{},{},{},{},{},{},{},{2,25}};
vector<vector<string>> MyObject::specnames = {{},{},{},{},{},{},{},{},{},{},{},{"wrong","Christmas"}};


MyObject::MyObject(){
}

MyObject::MyObject(int dayin){

}


MyObject::MyObject(int dayin, int  monthin){

}


MyObject::MyObject(int dayin, int  monthin, int yearin){
    day = dayin;
    month = monthin;
    year = yearin;
}
MyObject::MyObject(int dayin, int monthin, int yearin, string newevent){

    day = dayin;
    month = monthin;
    year = yearin;

    specnames[month-1].push_back("New Years");
    specdays[month-1].push_back(1);

}
MyObject::MyObject(int dayin, int monthin, int yearin, string newevent, int rem){


}




string MyObject::to_string(){

    return ::to_string(month) + "/" + ::to_string(day) + "/" + ::to_string(year);
}

string MyObject::special_day(){
   
    vector<int> specmonth = specdays[month-1];    
    int holder;
    string str;

    for (int i = 0; i < specmonth.size(); i++) {
	if (specmonth[i] == day){
	    holder = i;
}
    str = specnames[month-1][holder];
}
    return str;

}


