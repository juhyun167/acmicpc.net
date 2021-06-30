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

#define MAX		500

unsigned long long m, n, t;
int arr[MAX + 1][MAX + 1], dp[MAX + 1][MAX + 1];

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
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = arr[i][j] + dp[i - 1][j];
			} else if (j == i) {
				dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
			} else {
				dp[i][j] = arr[i][j] + 
						max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}
	}
	cout << *max_element(&dp[n - 1][0], &dp[n - 1][n]) << "\n";
	return 0;
}
