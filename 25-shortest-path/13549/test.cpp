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

void bfs_01(int s) {
	deque<int> dq;

	// initialize
	fill_n(&d[0], n, INF);
	d[s] = 0;

	dq.push_front(s);
	while (!dq.empty()) {
		int u = dq.front();

		dq.pop_front();
		for (const int &v : adj[u]) {
			// relaxation
			if (d[v] > d[u] + w[u][v]) {
				d[v] = d[u] + w[u][v];
				if (w[u][v] == 1) {
					dq.push_back(v);
				} else {
					dq.push_front(u);
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
