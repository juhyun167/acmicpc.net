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

#define MAX		(2000 + 1)

int m, n, t, k, v;
int arr[MAX];
bool dp[MAX][MAX];

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
		dp[i][i] = true;
	}

	for (int i = 1; i <= n - 1; i++) {
		dp[i][i + 1] = (arr[i] == arr[i + 1]);
	}
	for (int l = 3; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;

			dp[i][j] = (dp[i + 1][j - 1] && arr[i] == arr[j]);
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;

		cin >> s >> e;
		cout << (int) dp[s][e] << "\n";
	}

	return 0;
}
