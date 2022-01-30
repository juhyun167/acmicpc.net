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
unordered_map<int, tuple<int, int, char>> umap;

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
				if (umap.count(dp[i][j]) == 0) {
					umap[dp[i][j]] = make_tuple(i, j, s2[j - 1]);
					cout << dp[i][j] << " " << i << " " << j << " " << s2[j - 1] << "\n";
				} else {
					int r = get<0>(umap[dp[i][j]]);
					int c = get<1>(umap[dp[i][j]]);

					if (i 
						umap[dp[i][j]] = make_pair(j, s2[j - 1]);
						cout << dp[i][j] << " " << j << " " << s2[j - 1] << "\n";
					}
				}
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
}

string trace() {
	string result;

	for (int i = 1; i <= dp[n][m]; i++) {
		result += umap[i].second;
	}

	return result;
}

int main() {
	string result;

	setup();
	cin >> s1 >> s2;
	if (s1.length() < s2.length()) {
		swap(s1, s2);
	}
	n = s1.length(), m = s2.length();

	dp_func();
	result = trace();
	cout << result.size() << "\n";
	cout << result << "\n";

	return 0;
}

// acab cab -> WA aab
