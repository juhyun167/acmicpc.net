#include <iostream>
using namespace std;

#define MAX		10000

int n, t, arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	setup();

	while (true) {
		int a, b;
		
		cin >> a >> b;
		if (cin.eof()) {
			break;
		}
		cout << a + b << "\n";
	}
	return 0;
}
