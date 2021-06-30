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
	int cnt = 0, x;

	setup();
	cin >> n;
	x = n;
	while (true) {
		cnt += 1;
		x = ((x / 10) + (x % 10)) % 10 + (x % 10) * 10;
		if (x == n) {
			break;
		}
	}
	cout << cnt << "\n";
	return 0;
}
