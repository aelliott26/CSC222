#include "MyObject.h"
#include <iostream>
#include <string>

using namespace std;

MyObject::MyObject(){
    day = 1;
    month = 1;
    year = 1;
}

MyObject::MyObject(int dayin){
    day = dayin;
    month = 1;
    year = 1;
}


MyObject::MyObject(int dayin, int  monthin){
    day = dayin;
    month = monthin;
    year = 1;
}


MyObject::MyObject(int dayin, int  monthin, int yearin){
    day = dayin;
    month = monthin;
    year = yearin;
}

string MyObject::to_string(){

    return "This is MyObject";
}


