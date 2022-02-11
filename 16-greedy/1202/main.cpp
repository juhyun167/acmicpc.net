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

#define MAX		(300000 + 1)

int n, t, k;

struct jewel {
	int64_t m, v;

	jewel(int64_t m, int64_t v) : m(m), v(v) {}
};

vector<jewel> vec;
multiset<int> c;

bool compare(jewel& lhs, jewel& rhs) {
	return lhs.v > rhs.v;
}

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int64_t solve(int n) {
	int64_t result = 0;

	sort(vec.begin(), vec.end(), compare);

	for (const jewel& el : vec) {
		auto it = c.lower_bound(el.m);

		if (it == c.end()) {
			continue;
		}
		result += el.v;
		c.erase(it);
	}

	return result;
}

int main() {
	setup();
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int64_t m, v;

		cin >> m >> v;
		vec.push_back(jewel(m, v));
	}
	for (int i = 0; i < k; i++) {
		int x;

		cin >> x;
		c.insert(x);
	}

	cout << solve(n) << "\n";

	return 0;
}
