#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int t = 0;
    for (int i = 0; i < argc; i++) {
        cout << "Command line argument [" << i << "] is: ";
        cout << argv[i] << endl;
        ++t;
    }

    if (argv[t] == nullptr){
        cout << "Null" << endl;
        ++t;
        cout << argv[t] << endl;
        ++t;
        cout << argv[t] << endl;
    }

    return 0;
}
