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

#define MAX		300

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
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0][0] = dp[0][1] = arr[0];
	dp[1][0] = arr[1], dp[1][1] = arr[0] + arr[1];
	for (int i = 2; i < n; i++) {
		dp[i][0] = arr[i] + max(dp[i - 2][0], dp[i - 2][1]);
		dp[i][1] = arr[i] + dp[i - 1][0];
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
	return 0;
}
