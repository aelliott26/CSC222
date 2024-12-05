// #ifndef MYOBJECT_H
#define MYOBJECT_H
#include <string>
using namespace std;

struct MyObject {
    int day, month, year;

    static vector<vector<int>> specdays;
    static vector<vector<string>> specnames;



    MyObject();
    string to_string();
    MyObject(int dayin, int  monthin, int yearin);
    MyObject(int dayin, int  monthin);
    MyObject(int dayin);
    string special_day();
    MyObject(int dayin, int monthin, int yearin, string newevent);
    MyObject(int dayin, int monthin, int yearin, string newevent, int rem);


};

// #endif
