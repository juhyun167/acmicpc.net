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

unordered_map<int, int> orig_idx;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

vector<int> find_lis(vector<int>& vec) {
    vector<int> dp;         // last element of lis of length i + 1
    vector<int> idx;        // index of dp[i] in vec
    vector<int> parent;     // index of previous element for last element
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

bool compare(int& lhs, int& rhs) {
	return orig_idx[lhs] < orig_idx[rhs];
}

int main() {
	vector<int> vec, lis, ans;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;

		cin >> a >> b;
		vec.push_back(b);
		orig_idx[b] = a;
	}

	sort(vec.begin(), vec.end(), compare);

	lis = find_lis(vec);

	cout << n - lis.size() << "\n";
	for (const int& x : lis) {
		auto it = orig_idx.find(x);
		orig_idx.erase(it);
	}

	for (auto it = orig_idx.begin(); it != orig_idx.end(); it++) {
		ans.push_back(it->second);
	}
	sort(ans.begin(), ans.end());

	for (const int& x : ans) {
		cout << x << "\n";
	}

	return 0;
}
