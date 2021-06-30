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
long long dp[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
	fill_n(dp, MAX + 1, -1);
	dp[0] = 0, dp[1] = dp[2] = 1;
}

long long recursion(int k) {
	if (k < 3) {
		return dp[k];
	}
	for (int i = 3; i <= k; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}
	return dp[k];
}

int main() {
	setup();
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << recursion(n) << "\n";
	}
	return 0;
}
