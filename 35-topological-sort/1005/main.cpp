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
vector<int> adj[MAX];
vector<int> reverse_adj[MAX];
bool visited[MAX];

int b[MAX];		// build time
int f[MAX];		// finished time

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
		reverse_adj[i].clear();
	}
	fill_n(&visited[1], n, false);
}

void dfs(int u, vector<int>& result, int time) {
	time += b[u];
    for (const int& w : adj[u]) {
		if (!visited[w]) {
			visited[w] = true;
            dfs(w, result, time);
		}
    }
	result.emplace_back(u);
	f[u] = time;
}

vector<int> topological_sort() {
    vector<int> result;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
			visited[i] = true;
            dfs(i, result, 0);
        }
    }
    reverse(result.begin(), result.end());

    return result;
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		int w;
		vector<int> result;

		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < k; i++) {
			int a, b;

			cin >> a >> b;
			adj[a].emplace_back(b);
			reverse_adj[b].emplace_back(a);
		}
		cin >> w;

		result = topological_sort();

		for (const int& x : result) {
			for (const int& u : reverse_adj[x]) {
				f[x] = max(f[x], f[u] + b[x]);
			}
		}
		cout << f[w] << "\n";

		// clear
		clear(n);
	}

	return 0;
}
