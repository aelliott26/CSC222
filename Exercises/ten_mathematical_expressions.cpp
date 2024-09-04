#include <iostream>
using namespace std;

int main() {
int a = 1;
	for (int i = 0; i < 10; i++) {
	cout << "The product of " << a << " and " << ++a << " is ";
	cout << --a * ++a << "." << endl;
}
	return 0;
}
