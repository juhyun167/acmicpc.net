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
#include <iomanip>
using namespace std;

#define MAX		40

unsigned long long m, n, t;
int dp[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
	fill_n(dp, MAX + 1, -1);
	dp[0] = 0, dp[1] = 1;
}

int fibonacci(int n) {
	if (dp[n] >= 0) {
		return dp[n];
	}
	dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return dp[n];
}

int main() {
	setup();
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n == 0) {
			cout << "1 0\n";
		} else {
			cout << fibonacci(n - 1) << " " << fibonacci(n) << "\n";
		}
	}
	return 0;
}
