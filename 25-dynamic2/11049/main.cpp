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
#include <utility>
#include <iomanip>
using namespace std;

#define MAX		(500 + 1)

int m, n, t, k, v;
int r[MAX], c[MAX];
int dp[MAX][MAX];		// answer for A_i ... A_j

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
	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> c[i];
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			
			dp[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				dp[i][j] = min(dp[i][j],
								dp[i][k] + dp[k + 1][j] 
								+ r[i] * c[k] * c[j]
				);
			}
		}
	}

	cout << dp[1][n] << "\n";

	return 0;
}
