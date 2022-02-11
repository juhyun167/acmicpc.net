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

#define MAX	(10000000 + 1)

int m, n, t, k, v;
vector<vector<short>> dp;
vector<int> sum;

struct app {
	int m;
	short c;

	app() : m(0), c(0) {}
	app(int m, short c) : m(m), c(c) {}

	bool operator<(const app& other) const {
		return m < other.m;
	}
};

vector<app> vec;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	setup();
	cin >> n >> m;

	vec.resize(n + 1);
	sum.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> vec[i].m;
		sum[i] = sum[i - 1] + vec[i].m;
	}
	for (int i = 1; i <= n; i++) {
		cin >> vec[i].c;
	}

	dp.resize(2, vector<short>(sum[n] + 1, INT16_MAX));
	sort(vec.begin() + 1, vec.end());
	
	vector<short>& p1 = dp[0];
	vector<short>& p2 = dp[1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum[i]; j++) {
			if (j - vec[i].m == 0) {
				p2[j] = min(p1[j], vec[i].c);
			} else if (j - vec[i].m > 0
					&& p1[j - vec[i].m] != INT16_MAX) {
				p2[j] = (p1[j] < vec[i].c + p1[j - vec[i].m]) 
							? p1[j] : vec[i].c + p1[j - vec[i].m];
			} else {
				p2[j] = p1[j];
			}
		}
		swap(p1, p2);
	}
	cout << *min_element(p1.begin() + m, p1.begin() + sum[n] + 1) << "\n";

	return 0;
}
