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

#define MAX		1000

unsigned long long m, n, t;
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int getLength(vector<int> &v) {
	int n = v.size();
	int dp[MAX + 1] = { 0 };

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int maxRes = INT_MIN;

		for (int j = i - 1; j >= 0; j--) {
			if (v[j] < v[i] && maxRes< 1 + dp[j]) {
				maxRes = 1 + dp[j];
			}
		}
		maxRes = (maxRes == INT_MIN) ? 1 : maxRes;
		dp[i] = maxRes;
	}
	return dp[n - 1];
}

int main() {
	int maxRes = INT_MIN;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		vector<int> v1, v2;

		for (int j = 0; j <= i; j++) {
			v1.emplace_back(arr[j]);
		}
		for (int j = n - 1; j >= i; j--) {
			v2.emplace_back(arr[j]);
		}
		int res = getLength(v1) + getLength(v2);
		maxRes = (res > maxRes) ? res : maxRes;
	}
	cout << maxRes - 1 << "\n";
	return 0;
}
