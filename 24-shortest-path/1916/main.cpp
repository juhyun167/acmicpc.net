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

int m, n, t, k, v, a, b;
unordered_map<int, int> w[MAX];
int d[MAX];

const int INF = INT_MAX / 2;

auto compare = [](int& lhs, int& rhs) -> bool {
	return d[lhs] > d[rhs];
};

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void djkstra() {
	priority_queue<int, vector<int>, decltype(compare)>
		pq(compare);

	fill_n(&d[1], n, INF);
	d[a] = 0;

	pq.push(a);
	while (!pq.empty()) {
		int u = pq.top();
		
		pq.pop();
		unordered_map<int, int>::iterator it;
		for (it = w[u].begin(); it != w[u].end(); it++) {
			int v = it->first, weight = it->second;

			if (d[v] > d[u] + weight) {
				d[v] = d[u] + weight;
				pq.push(v);
			}
		}
	}
}

int main() {
	setup();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, t, weight;

		cin >> s >> t >> weight;
		if (w[s].count(t) == 0) {
			w[s][t] = weight;
		} else {
			w[s][t] = min(w[s][t], weight);
		}
	}
	cin >> a >> b;
	djkstra();
	cout << d[b] << "\n";

	return 0;
}
