#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX		1000000

int n, t, arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

bool test(int x) {
	vector<int> v;
	int d = 11;

	while (x != 0) {
		v.emplace_back(x % 10);
		x = (x - x % 10) / 10;
	}
	for (auto it = v.begin(); it != v.end() -1 ; it++) {
		if (d == 11) {
			d = *it - *(it + 1);
		} else {
			if (d != *it - *(it + 1)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int cnt = 0;

	setup();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (test(i)) {
			cnt += 1;
		}
	}
	cout << cnt << "\n";

	return 0;
}