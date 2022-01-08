#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdint>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue>
#include <list>
#include <iomanip>
using namespace std;

#define MAX		(500000 + 1)

int m, n, t, k, v;
bool broken[10];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int digit(int n) {
    if (n < 0) {
		return digit((n == INT_MIN) ? INT_MAX : -n);
	}
    if (n < 10) {
		return 1;
	}
    return 1 + digit(n / 10);
}

bool check(int n) {
	if (n == 0) {
		return !broken[n];
	}
	while (n != 0) {
		if (broken[n % 10]) {
			return false;
		}
		n /= 10;
	}
	return true;
}

inline int count(int x, int n) {
	return digit(x) + abs(x - n);
}

int main() {
	int cnt1 = INT_MAX, cnt2 = INT_MAX;
	int cnt3 = INT_MAX;		// move from 100

	setup();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;

		cin >> x;
		broken[x] = true;
	}

	for (int i = 0; n + i < MAX * 2; i++) {
		if (check(n + i)) {
			cnt1 = count(n + i, n);
			break;
		}
	}
	for (int i = 0; n - i >= 0; i++) {
		if (check(n - i)) {
			cnt2 = count(n - i, n);
			break;
		}
	}
	cnt3 = abs((int) (100 - n));
	cout << min({ cnt1, cnt2, cnt3 }) << "\n";

	return 0;
}
