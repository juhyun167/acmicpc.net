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
int dp[MAX + 1] = { 0, 1, 2 };

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int fibonacci(int k) {
	if (k < 3) {
		return dp[k];
	}
	for (int i = 3; i <= k; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	return dp[k];
}

int main() {
	setup();
	cin >> n;
	cout << fibonacci(n) << "\n";
	return 0;
}
