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

#define MAX		(100000 + 1)

int m, n, t, k, v;
int d[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

inline bool in_range(int x) {
	return 0 <= x && x < MAX;
}

int get_neighbor(int x, int i) {
	switch (i) {
		case 0:
			return x - 1;
		case 1:
			return x + 1;
		case 2:
			return 2 * x;
		default:
			return -1;
	}
}

pair<int, int> search() {
	queue<int> qu;
	int cnt = 0;

	d[n] = 0;
	qu.push(n);
	while (!qu.empty()) {
		int u = qu.front();

		qu.pop();
		if (u == k) {
			cnt++;
			continue;
		}
		for (int i = 0; i < 3; i++) {
			int w = get_neighbor(u, i);

			if (!in_range(w)) {
				continue;
			}
			if (d[u] + 1 <= d[w]) {
				d[w] = d[u] + 1;
				qu.push(w);
			}
		}
	}

	return { d[k], cnt };
}

int main() {
	pair<int, int> result;

	setup();
	cin >> n >> k;

	fill_n(&d[0], MAX, INT_MAX);
	result = search();
	cout << result.first << "\n";
	cout << result.second << "\n";

	return 0;
}
