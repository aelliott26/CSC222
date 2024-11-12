#include <string>
#include <vector>
using namespace std;

string render_num_vector(const vector<int>& vect) {
    string s = "";
    for (int i = 0; i < vect.size(); i++){
	s += to_string(vect[i]) + " ";
}
    return s;
}

