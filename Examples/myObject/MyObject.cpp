#include "MyObject.h"
#include <iostream>
#include <string>

using namespace std;

MyObject::MyObject(){
    cerr << " You need a day month and year" << endl;
}

MyObject::MyObject(int dayin){
    cerr << "Only provided day, needs month and year" << endl;

}


MyObject::MyObject(int dayin, int  monthin){
    cerr << "Only provided day and month, needs year" << endl;

}


MyObject::MyObject(int dayin, int  monthin, int yearin){
    day = dayin;
    month = monthin;
    year = yearin;
}

string MyObject::to_string(){

    return "This is MyObject";
}


