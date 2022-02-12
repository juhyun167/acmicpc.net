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

#define MAX		(1000000 + 1)

int m, n, t, k, v;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

vector<int> find_lis(vector<int>& vec) {
	vector<int> dp;			// last element of lis of length i + 1
	vector<int> idx;		// index of dp[i] in vec
	vector<int> parent;		// index of previous element for last element
							// of lis ending in vec[i]
	vector<int> lis;
	int aidx;

	for (int i = 0; i < n; i++) {
		auto it = lower_bound(dp.begin(), dp.end(), vec[i]);
		int didx = it - dp.begin();

		if (it == dp.end()) {
			dp.push_back(vec[i]);
			parent.push_back((!idx.empty()) ? idx.back() : -1);
			idx.push_back(i);
		} else {
			*it = vec[i];
			parent.push_back((didx != 0) ? idx[didx - 1] : -1);
			idx[didx] = i;
		}
	}

	aidx = idx[dp.size() - 1];
	while (aidx != -1) {
		lis.push_back(vec[aidx]);
		aidx = parent[aidx];
	}
	reverse(lis.begin(), lis.end());

	return lis;
}

int main() {
	vector<int> vec, lis;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;

		cin >> x;
		vec.push_back(x);
	}

	lis = find_lis(vec);

	cout << lis.size() << "\n";
	for (const int& x : lis) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}
