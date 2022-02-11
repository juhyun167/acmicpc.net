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

#define MAX		(500 + 2)

int m, n, t, k, v;
unordered_map<int, int> w[MAX];
int d[MAX];

const int INF = INT_MAX / 2;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

bool bellman() {
	// initialize
	fill_n(&d[1], n, INF);
	d[n + 1] = 0;

	for (int i = 0; i < n + 1; i++) {
		for (int u = 1; u <= n + 1; u++) {
			unordered_map<int, int>::iterator it;
			for (it = w[u].begin(); it != w[u].end(); it++) {
				// relaxation
				int v = it->first, weight = w[u][v];

				d[v] = min(d[v], d[u] + weight);
			}
		}
	}

	for (int u = 1; u <= n + 1; u++) {
		unordered_map<int, int>::iterator it;
		for (it = w[u].begin(); it != w[u].end(); it++) {
			int v = it->first, weight = w[u][v];

			if (d[v] > d[u] + weight) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		int nw;

		cin >> n >> m >> nw;
		for (int i = 0; i < m + nw; i++) {
			int u, v, weight;

			cin >> u >> v >> weight;
			if (i < m) {
				if (w[v].count(u) == 0) {
					w[v][u] = weight;
				} else {
					w[v][u] = min(w[v][u], weight);
				}
			} else {
				weight = -weight;
			}
			if (w[u].count(v) == 0) {
				w[u][v] = weight;
			} else {
				w[u][v] = min(w[u][v], weight);
			}
		}

		// add ghost vertex for starting point
		for (int i = 1; i <= n; i++) {
			w[n + 1][i] = 0;
		}

		if (!bellman()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		
		// clear weight map
		for (int i = 1; i <= n + 1; i++) {
			w[i].clear();
		}
	}

	return 0;
}
