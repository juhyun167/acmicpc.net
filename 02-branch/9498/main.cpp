#include <iostream>
using namespace std;

int main() {
	int n;

	cin >> n;
	
	if (90 <= n && n <= 100) {
		cout << "A\n";
	} else if (80 <= n && n < 90) {
		cout << "B\n";
	} else if (70 <= n && n < 80) {
		cout << "C\n";
	} else if (60 <= n && n < 70) {
		cout << "D\n";
	} else {
		cout << "F\n";
	}
	return 0;
}
