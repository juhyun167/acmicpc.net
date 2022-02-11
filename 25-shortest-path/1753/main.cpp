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
#include <iomanip>
using namespace std;

#define MAX     (20000 + 1)

int m, n, t, k, v;
vector<int> adj[MAX];
unordered_map<int, int> w[MAX];		// weight
int d[MAX];							// distance

const int INF = INT_MAX / 2;

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

	// initialize
	fill_n(&d[1], n, INF);
	d[s] = 0;

	pq.push(s);
    while (!pq.empty()) {
        int u = pq.top();

        pq.pop();
        for (const int &v : adj[u]) {
			// relaxation
			if (d[v] > d[u] + w[u][v]) {
				d[v] = d[u] + w[u][v];
				pq.push(v);
			}
        }
    }
}

int main() {
    int s;

    setup();
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int s, t, weight;

        cin >> s >> t >> weight;
		if (w[s].find(t) == w[s].end()) {
			w[s][t] = weight;
			adj[s].emplace_back(t);
		} else {
			w[s][t] = (weight < w[s][t]) ? weight : w[s][t];
		}
    }

    djkstra(s);

    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) {
            cout << "INF\n";
        } else {
            cout << d[i] << "\n";
        }
    }

    return 0;
}
