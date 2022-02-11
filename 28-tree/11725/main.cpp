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

#define MAX		(100000 + 1)

int m, n, t, k, v;
vector<int> adj[MAX];
vector<int> parent(MAX);
bool visited[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void bfs(int v) {
	queue<int> qu;

	visited[v] = true;
	qu.push(v);
	while (!qu.empty()) {
		int u = qu.front();

		qu.pop();
		for (const int& w : adj[u]) {
			if (!visited[w]) {
				visited[w] = true;
				parent[w] = u;
				qu.push(w);
			}
		}
	}
}

int main() {
	setup();
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int s, t;

		cin >> s >> t;
		adj[s].emplace_back(t);
		adj[t].emplace_back(s);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}

	return 0;

}
