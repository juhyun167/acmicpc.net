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
#include <bitset>
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

void bfs(vector<list<int>> &adj, int v) {
	unordered_set<int> visited;
	queue<int> qu;

	qu.push(v);
	while (!qu.empty()) {
		int u = qu.front();

		qu.pop();
		if (find(visited.begin(), visited.end(), u) == visited.end()) {
			visited.insert(u);
			cout << u << " ";
			for (auto iter = adj[u].begin(); iter != adj[u].end(); iter++) {
				qu.push(*iter);
			}
		}
	}
	cout << "\n";
}

void dfs(vector<list<int>> &adj, int v) {
	unordered_set<int> visited;
	stack<int> st;

	st.push(v);
	while (!st.empty()) {
		int u = st.top();

		st.pop();
		if (find(visited.begin(), visited.end(), u) == visited.end()) {
			visited.insert(u);
			cout << u << " ";
			for (auto iter = adj[u].rbegin(); iter != adj[u].rend(); iter++) {
				st.push(*iter);
			}
		}
	}
	cout << "\n";
}

int main() {
	vector<list<int>> adj;

	setup();
	cin >> n >> m >> v;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int s, t;
		list<int>::iterator iter;

		cin >> s >> t;
		iter = lower_bound(adj[s].begin(), adj[s].end(), t);
		adj[s].insert(iter, t);
		iter = lower_bound(adj[t].begin(), adj[t].end(), s);
		adj[t].insert(iter, s);
	}

	dfs(adj, v);
	bfs(adj, v);

	return 0;
}
