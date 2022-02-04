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

#define MAX		(32000 + 1)

int m, n, k, v;
vector<int> adj[MAX];
bool visited[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void dfs(int u, vector<int>& result) {
	for (const int& w : adj[u]) {
		if (!visited[w]) {
			visited[w] = true;
			dfs(w, result);
		}
	}
	result.emplace_back(u);
}

vector<int> topological_sort() {
	vector<int> result;

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, result);
		}
	}
	reverse(result.begin(), result.end());

	return result;
}

int main() {
	vector<int> result;

	setup();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, t;

		cin >> s >> t;
		adj[s].emplace_back(t);
	}

	result = topological_sort();
	for (const int& x : result) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}
