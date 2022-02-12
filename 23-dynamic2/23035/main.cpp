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

#define MAX		(1000000000 + 1)

int m, n, t, k, v;

struct cat {
	int r, c;

	cat(int r, int c) : r(r), c(c) {}

	bool operator<(const cat& other) const {
		return (r == other.r) ? c < other.c : r < other.r;
	}
};

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

vector<int64_t> find_lis(vector<int64_t>& vec) {
    vector<int64_t> dp;         // last element of lis of length i + 1
    vector<int> idx;        // index of dp[i] in vec
    vector<int> parent;     // index of previous element for last element
                            // of lis ending in vec[i]
    vector<int64_t> lis;
    int aidx;

    for (int i = 0; i < vec.size(); i++) {
        auto it = upper_bound(dp.begin(), dp.end(), vec[i]);
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
	vector<cat> cats;
	vector<int64_t> vec, lis;
	int result = 0;

	setup();
	cin >> n >> m >> t;
	while (t--) {
		int r, c;

		cin >> r >> c;
		if (r > n || c > m) {
			continue;
		}
		cats.push_back(cat(r, c));
	}

	sort(cats.begin(), cats.end());
	for (const cat& c : cats) {
		vec.push_back(c.c);
	}

	lis = find_lis(vec);
	cout << lis.size() << "\n";

	return 0;
}
