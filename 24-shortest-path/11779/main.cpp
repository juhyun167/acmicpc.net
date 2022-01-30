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

#define MAX		(1000 + 1)

int m, n, t, k, v;
unordered_map<int, int> w[MAX];
int d[MAX], parent[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

auto compare = [](int &lhs, int &rhs) -> bool {
    return d[lhs] > d[rhs];
};

void djkstra(int s) {
    priority_queue<int, vector<int>, decltype(compare)>
        pq(compare);
    const int INF = INT_MAX / 2;

    // initialize
    fill_n(&d[1], n, INF);
    d[s] = 0;

    pq.push(s);
    while (!pq.empty()) {
        int u = pq.top();
        unordered_map<int, int>::iterator it;

        pq.pop();
        for (it = w[u].begin(); it != w[u].end(); it++) {
            // relaxation
            int v = it->first;

            if (d[v] > d[u] + w[u][v]) {
                d[v] = d[u] + w[u][v];
				parent[v] = u;
                pq.push(v);
            }
        }
    }
}

void trace(int a, int b, vector<int>& path) {
	while (b != a) {
		path.emplace_back(b);
		b = parent[b];
	}
	path.emplace_back(a);
	reverse(path.begin(), path.end());
}

int main() {
	vector<int> path;
	int a, b;

	setup();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, t, c;

		cin >> s >> t >> c;
		if (w[s].count(t) == 0) {
			w[s][t] = c;
		} else {
			w[s][t] = min(w[s][t], c);
		}
	}
	cin >> a >> b;

	djkstra(a);
	trace(a, b, path);

	cout << d[b] << "\n";
	cout << path.size() << "\n";
	for (const int& x : path) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}
