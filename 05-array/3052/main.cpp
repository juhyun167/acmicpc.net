#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

#define MAX		1000000

int n, t, arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	int cnt = 0;

	setup();
	for (int i = 0; i < 10; i++) {
		cin >> n;
		arr[n % 42] += 1;
	}
	for (int i = 0; i < 42; i++) {
		if (arr[i] > 0) {
			cnt += 1;
		}
	}
	cout << cnt << "\n";
	return 0;
}
