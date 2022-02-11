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

#define MAX		100

unsigned long long m, n, t;
unsigned long long dp[MAX + 1][10];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
}

int main() {
	setup();
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			switch (j) {
				case 0:
					dp[i][j] = dp[i - 1][j + 1] % 1000000000;
					break;
				case 9:
					dp[i][j] = dp[i - 1][j - 1] % 1000000000;
					break;
				default:
					dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) %
							1000000000;
					break;
			}
		}
	}
	unsigned long long res = 0;
	for (int i = 0; i <= 9; i++) {
		res += dp[n][i];
	}
	cout << res % 1000000000 << "\n";
	return 0;
}
