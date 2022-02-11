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

#define MAX		10000

unsigned long long m, n, t;
int arr[MAX + 1], dp[MAX + 1][2];

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
		cin >> arr[i];
	}

	dp[1][0] = dp[1][1] = arr[1];
	dp[2][0] = arr[2], dp[2][1] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i][0] = arr[i] + max({
			dp[i - 2][0], dp[i - 2][1], dp[i - 3][0], dp[i - 3][1]
		});
		dp[i][1] = arr[i] + dp[i - 1][0];
	}
	int maxRes = max({
		dp[n][0], dp[n][1], dp[n - 1][0], dp[n - 1][1]
	});
	cout << maxRes << "\n";
	return 0;
}
