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
string a, b;
int dp[MAX + 1][MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	int lenA, lenB;

	setup();
	cin >> a >> b;
	lenA = a.length(), lenB = b.length();
	for (int i = 1; i <= lenB; i++) {
		for (int j = 1; j <= lenA; j++) {
			if (a[j - 1] == b[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[lenB][lenA] << "\n";
	return 0;
}
