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
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = (dp[i - 1] > 0) ? arr[i] + dp[i - 1] : arr[i];
	}
	cout << *max_element(&dp[0], &dp[n]) << "\n";
	return 0;
}
