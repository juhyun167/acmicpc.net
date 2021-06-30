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
int arr[MAX + 1], dp[MAX + 1];

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
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int maxRes = INT_MIN;

		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i] && maxRes < 1 + dp[j]) {
				maxRes = 1 + dp[j];
			}
		}
		maxRes = (maxRes == INT_MIN) ? 1 : maxRes;
		dp[i] = maxRes;
	}
	cout << *max_element(&dp[0], &dp[n]) << "\n";
	return 0;
}
