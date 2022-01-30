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
int d[MAX], r[MAX];		// r for return cost

const int INF = INT_MAX / 2;

auto compare = [](int& lhs, int& rhs) -> bool {
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
	int x;

	setup();
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int s, t, weight;

		cin >> s >> t >> weight;
		w[s][t] = weight;
	}

	// compute return cost
	djkstra(x);
	for (int i = 1; i <= n; i++) {
		r[i] = d[i];
	}

	// compute cost for each person
	for (int i = 1; i <= n; i++) {
		djkstra(i);
		r[i] += d[x];
	}

	cout << *max_element(&r[1], &r[n + 1]) << "\n";

	return 0;
}
