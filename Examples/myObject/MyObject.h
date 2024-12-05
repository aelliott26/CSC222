// #ifndef MYOBJECT_H
#define MYOBJECT_H
#include <string>
using namespace std;

struct MyObject {
    int day, month, year;

    vector<vector<int>> specdays {{},{},{},{},{},{},{},{},{},{},{},{2,25}};
    vector<vector<string>> specnames {{},{},{},{},{},{},{},{},{},{},{},{"wrong","Christmas"}};


    MyObject();
    string to_string();
    MyObject(int dayin, int  monthin, int yearin);
    MyObject(int dayin, int  monthin);
    MyObject(int dayin);
    string special_day();
    MyObject(int dayin, int monthin, int yearin, string newevent);
};

// #endif
