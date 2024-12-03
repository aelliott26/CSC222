#include "MyObject.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

string MyObject::to_string(){

    return ::to_string(month) + "/" + ::to_string(day) + "/" + ::to_string(year);
}

string MyObject::special_day(){
    vector<vector<int>> specdays {{},{},{},{},{},{},{},{},{},{},{},{2,25}};
    vector<vector<string>> specnames {{},{},{},{},{},{},{},{},{},{},{},{"wrong","Christmas"}};
    return "nope";


}


