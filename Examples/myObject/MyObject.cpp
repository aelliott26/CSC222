#include "MyObject.h"
#include <iostream>
#include <string>

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


