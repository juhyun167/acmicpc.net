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

#define MAX		(1000000 + 1)

int m, n, t, k, v;
int arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

inline bool check(int k, int m, int n, int x, int y) {
	return k % m == x % m && k % n == y % n;
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		int x, y, d, l;

		cin >> m >> n >> x >> y;
		if (x < y) {
			swap(x, y);
			swap(m, n);
		}
		d = gcd(m, n);
		l = m * n / d;

		for (int k = x; k <= l; k += m) {
			if (check(k, m, n, x, y)) {
				cout << k << "\n";
				goto Found;
			}
		}
		cout << "-1\n";
Found:
		continue;
	}

	return 0;
}
