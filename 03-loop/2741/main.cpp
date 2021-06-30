#include <iostream>
using namespace std;

int n, t;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	setup();
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cout << i << "\n";
	}
	return 0;
}
