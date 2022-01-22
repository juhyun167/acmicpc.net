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

const int INF = INT_MAX / 2;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

pair<int, int> neighbor(int x, int k) {
	switch (k) {
		case 0:
			return { x - 1, 1 };
		case 1:
			return { x + 1, 1 };
		default:
			return { 2 * x, 0 };
	}
}

inline bool check(int x) {
	return 0 <= x && x < MAX;
}

void bfs_01() {
	deque<int> dq;

	// initialization
	fill_n(&d[0], MAX, INF);
	d[n] = 0;

	dq.push_front(n);
	while (!dq.empty()) {
		int u = dq.front();

		dq.pop_front();
		for (int i = 0; i < 3; i++) {
			int v, w;

			tie(v, w) = neighbor(u, i);
			if (!check(v)) {
				continue;
			}
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				if (w == 1) {
					dq.push_back(v);
				} else {
					dq.push_front(v);
				}
			}
		}
	}
}

int main() {
	setup();
	cin >> n >> k;

	bfs_01();
	cout << d[k] << "\n";

	return 0;
}
