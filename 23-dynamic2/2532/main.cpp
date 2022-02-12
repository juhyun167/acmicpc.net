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
int arr[MAX];

struct animal {
	int s, e;

	animal() : s(0), e(0) {}
	animal(int s, int e) : s(s), e(e) {}

	bool operator<(const animal& other) const {
		int x1 = this->s, x2 = this->e;
		int x3 = other.s, x4 = other.e;

		return (
				(x1 > x3 && x2 < x4)
				|| (x1 == x3 && x2 < x4)
				|| (x1 > x3 && x2 == x4)
		);
	}
	bool operator==(const animal& other) const {
		return s == other.s && e == other.e;
	}
};

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

vector<animal> find_lis(vector<animal>& vec) {
    vector<animal> dp;       	// last element of lis of length i + 1
    vector<int> idx;       		// index of dp[i] in vec
    vector<int> parent;    		// index of previous element for last element
                           		// of lis ending in vec[i]
    vector<animal> lis;
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

bool compare(animal& lhs, animal& rhs) {
	return (lhs.s == rhs.s) ? lhs.e > rhs.e : lhs.s < rhs.s;
}

int main() {
	vector<animal> vec;

	setup();
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		int idx, s, e;

		cin >> idx >> s >> e;
		vec[idx - 1].s = s, vec[idx - 1].e = e;
	}

	sort(vec.begin(), vec.end(), compare);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	reverse(vec.begin(), vec.end());

	cout << find_lis(vec).size() << "\n";

	return 0;
}
