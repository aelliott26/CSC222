// #ifndef DATE_H
#define DATE_H
#include <string>
#include <vector>
using namespace std;

struct Date {
    int day, month, year;

    static vector<vector<int>> specdays;
    static vector<vector<string>> specnames;



    Date();
    string to_string();
    Date(int dayin, int  monthin, int yearin);
    Date(int dayin, int  monthin);
    Date(int dayin);
    string special_day();
    Date(int dayin, int monthin, int yearin, string newevent);
    // Date(int dayin, int monthin, int yearin, string newevent, int rem);


};

// #endif
