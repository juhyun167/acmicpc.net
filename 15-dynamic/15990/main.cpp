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

#define MAX		1000000

uint64_t m, n, t, k;
uint64_t dp[MAX + 1][3 + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	setup();
	cin >> t;
	dp[1][1] = 1, dp[1][2] = 0, dp[1][3] = 0;
	dp[2][1] = 0, dp[2][2] = 1, dp[2][3] = 0;
	dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;
	while (t--) {
		cin >> n;

		if (dp[n][1] + dp[n][2] + dp[n][3] == 0) {
			for (int i = 4; i <= n; i++) {
				dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
				dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
				dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
			}
		}
		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << "\n";
	}
	return 0;
}
