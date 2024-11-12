#include <string>
#include <vector>
using namespace std;

string render_num_vector(const vector<int>& vect) {
    string s = "", ss;
    for (int i = 0; i < vect.size(); i++){
	s += to_string(vect[i]) + " ";
}
    ss = s.substr(0, s.size()-1);
    return ss;
}


int num_vector_sum(const vector<int>& vect) {
    int nums = 0;
    for (int i = 0; i < vect.size(); i++){
	nums += vect[i];
}
    return nums;
}
