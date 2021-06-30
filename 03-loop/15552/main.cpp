#include <iostream>
using namespace std;

int n, t;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	int a, b;

	setup();
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}
