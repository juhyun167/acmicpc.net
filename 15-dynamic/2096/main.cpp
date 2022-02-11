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

#define MAX		(100000 + 1)

int m, n, t, k, v;
uint8_t arr[MAX][3];
int dp[MAX][3];

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
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		arr[i][0] -= '0';
		arr[i][1] -= '0';
		arr[i][2] -= '0';
	}
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	
	// max
	for (int i = 1; i < n; i++) {
		dp[i][0] = arr[i][0] + max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = arr[i][1]
							+ max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
		dp[i][2] = arr[i][2] + max(dp[i - 1][1], dp[i - 1][2]);
	}
	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << " ";
	
	//min
	for (int i = 1; i < n; i++) {
		dp[i][0] = arr[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = arr[i][1]
							+ min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
		dp[i][2] = arr[i][2] + min(dp[i - 1][1], dp[i - 1][2]);
	}
	cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << "\n";

	return 0;
}
