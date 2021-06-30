#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <iomanip>
using namespace std;

#define MAX		1000000

unsigned long long m, n, t;
int dp[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	setup();
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int m1 = INT_MAX, m2 = INT_MAX, m3 = INT_MAX;

		if (i % 3 == 0) {
			m1 = 1 + dp[i / 3];
		}
		if (i % 2 == 0) {
			m2 = 1 + dp[i / 2];
		}
		m3 = 1 + dp[i - 1];
		dp[i] = min({m1, m2, m3});
	}
	cout << dp[n] << "\n";
	return 0;
}
