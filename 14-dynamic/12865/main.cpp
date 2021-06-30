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

#define MAX		100000
#define MAX_N	100

unsigned long long m, n, t, k;
int w[MAX + 1], v[MAX + 1];
int dp[MAX_N + 1][MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	setup();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - w[i] >= 0) {
				dp[i][j] = max({
					v[i] + dp[i - 1][j - w[i]], dp[i - 1][j], dp[i][j - 1]
				});
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[n][k] << "\n";
	return 0;
}
