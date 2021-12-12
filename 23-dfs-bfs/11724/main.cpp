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

#define MAX		1000000

uint64_t m, n, t, k, v;
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	vector<list<int>> adj;
	unordered_set<int> visited;
	int cnt = 0;

	setup();
	cin >> n >> m;
	adj.resize(n + 1);
	while (m--) {
		int s, t;

		cin >> s >> t;
		adj[s].emplace_back(t);
		adj[t].emplace_back(s);
	}
	for (int i = 1; i <= n; i++) {
		visited.insert(i);
	}

	while (!visited.empty()) {
		unordered_set<int> __visited;
		queue<int> qu;

		qu.push(*(visited.begin()));
		while (!qu.empty()) {
			int u = qu.front();

			qu.pop();
			if (find(__visited.begin(), __visited.end(), u) == __visited.end()) {
				__visited.insert(u);
				visited.erase(u);
				for (auto iter = adj[u].begin(); iter != adj[u].end(); iter++) {
					qu.push(*iter);
				}
			}
		}
		cnt++;
	}
	cout << cnt << "\n";

	return 0;
}
