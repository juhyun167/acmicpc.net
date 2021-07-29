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
#include <iomanip>
using namespace std;

#define MAX		1000

uint64_t m, n, t, k;
int dp[MAX + 1][10];

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
	fill_n(&dp[1][0], 10, 1);
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			dp[i][j] = accumulate(&dp[i - 1][0], &dp[i - 1][j + 1], 0) % 10007;
		}
	}
	cout << accumulate(&dp[n][0], &dp[n][9 + 1], 0) % 10007 << "\n";
	return 0;
}
