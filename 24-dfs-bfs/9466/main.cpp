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
vector<int> adj[MAX];
bool visited[MAX];
unordered_set<int> has_team;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void clear(int n) {
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
	has_team.clear();
}

void dfs(int u, int k, unordered_map<int, int>& len,
			stack<int>& path, vector<bool>& visited) {
	int l;

	for (const int& w : adj[u]) {
		if (has_team.count(w) != 0) {
			continue;
		}
		if (!visited[w] && len.count(w) == 0) {
			visited[w] = true;
			len[w] = k;
			path.push(w);
			dfs(w, k + 1, len, path, visited);
		} else if (len.count(w) != 0) {
			has_team.insert(w);
			l = k - len[w];
			for (int i = 0; i < l; i++) {
				has_team.insert(path.top());
				path.pop();
			}
		}
	}
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		vector<bool> visited;

		cin >> n;
		visited.assign(n + 1, false);
		for (int i = 1; i <= n; i++) {
			int w;

			cin >> w;
			adj[i].push_back(w);
			if (i == w) {
				has_team.insert(i);
			}
		}

		for (int i = 1; i <= n; i++) {
			unordered_map<int, int> len;
			stack<int> path;

			if (!visited[i] && has_team.count(i) == 0) {
				visited[i] = true;
				len[i] = 1;
				path.push(i);
				dfs(i, 1, len, path, visited);
			}
		}
		cout << n - has_team.size() << "\n";

		clear(n);
	}

	return 0;
}
