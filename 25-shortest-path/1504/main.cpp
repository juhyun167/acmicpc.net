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

#define MAX		(800 + 1)

int m, n, t, k, v, e;
unordered_map<int, int> w[MAX];
int d[MAX];

const int INF = INT_MAX / 2;

auto compare = [](int &lhs, int &rhs) -> bool {
    return d[lhs] > d[rhs];
};

void djkstra(int s) {
    priority_queue<int, vector<int>, decltype(compare)>
        pq(compare);

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
                pq.push(v);
            }
        }
    }
}

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	int v1, v2;
	int r1 = 0, r2 = 0;

	setup();
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		w[a][b] = w[b][a] = c;
	}
	cin >> v1 >> v2;

	djkstra(1);
	if (d[v1] == INF) {
		cout << "-1\n";
		return 0;
	}
	r1 += d[v1];
	r2 += d[v2];

	djkstra(v1);
	if (d[v2] == INF) {
		cout << "-1\n";
		return 0;
	}
	r1 += d[v2];
	r2 += d[n];

	djkstra(v2);
	if (d[v1] == INF) {
		cout << "-1\n";
		return 0;
	}
	r1 += d[n];
	r2 += d[v1];

	cout << min(r1, r2) << "\n";

	return 0;
}
