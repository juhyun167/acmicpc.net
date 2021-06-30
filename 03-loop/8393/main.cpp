#include <iostream>
using namespace std;

int n, t;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	int sum = 0, i;

	setup();
	cin >> n;

	for (i = 1; i <= n; i++) {
		sum += i;
	}
	cout << sum << "\n";
	return 0;
}
