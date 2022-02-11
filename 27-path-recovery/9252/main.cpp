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

#define MAX		(1000 + 1)

int m, n, t, k, v;
string s1, s2;
int dp[MAX][MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void dp_func() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
}

string trace() {
	string result;
	int i = n, j = m, x = dp[i][j];

	while (x > 0) {
		while (dp[i][j] >= x) {
			j--;
		}
		j++;
		while (dp[i][j] >= x) {
			i--;
		}
		i++;
		result.push_back(s2[j - 1]);
		x--;
		i--;
		j--;
	}
	reverse(result.begin(), result.end());

	return result;
}

int main() {
	string result;

	setup();
	cin >> s1 >> s2;
	if (s1.length() > s2.length()) {
		swap(s1, s2);
	}
	n = s1.length(), m = s2.length();

	dp_func();
	result = trace();
	cout << result.size() << "\n";
	cout << result << "\n";

	return 0;
}
