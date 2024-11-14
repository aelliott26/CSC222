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


int num_vector_product(const vector<int>& vect) {
    int nums = 1;
    for (int i = 0; i < vect.size(); i++){
        nums = nums * vect[i];
}
    return nums;
}

vector<int> only_evens(const vector<int>& vect) {
    vector<int> s;
    int check;
    for (int i = 0; i < vect.size(); i++){
    check = vect[i] % 2;
    if (check == 0){    
	s.push_back(vect[i]);
}
}
    return s;
}
vector<int> only_odds(const vector<int>& vect) {
    vector<int> s;
    int check;
    for (int i = 0; i < vect.size(); i++){
    check = vect[i] % 2;
    if (check == 1){
        s.push_back(vect[i]);
}
}
    return s;
}

vector<int> nums_between(const vector<int>& vect, int num1, int num2) {
    vector<int> s;
    int check;
    for (int i = 0; i < vect.size(); i++){
    check = vect[i] >= num1 and vect[i] <= num2;
    if (check == 1){    
	s.push_back(vect[i]);
}
}
    return s;
}

double num_vector_mean(const vector<int>& vect) {
    double s = 0;
    for (int i = 0; i < vect.size(); i++){
        s += vect[i];
}
    s /= vect.size();
    return s;
}



