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

void bfs(vector<list<int>> &adj, int v) {
    unordered_set<int> visited;
    queue<int> qu;

    qu.push(v);
    while (!qu.empty()) {
        int u = qu.front();

        qu.pop();
        if (find(visited.begin(), visited.end(), u) == visited.end()) {
            visited.insert(u);
            for (auto iter = adj[u].begin(); iter != adj[u].end(); iter++) {
                qu.push(*iter);
            }
        }
    }
	cout << visited.size() - 1 << "\n";
}

int main() {
	vector<list<int>> adj;

	setup();
	cin >> n >> m;
	adj.resize(n + 1);
	while (m--) {
		int s, t;

		cin >> s >> t;
		adj[s].emplace_back(t);
		adj[t].emplace_back(s);
	}
	bfs(adj, 1);

	return 0;
}
