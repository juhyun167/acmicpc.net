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

#define MAX		(500 + 1)

int m, n, t, k, v;
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

bool has_cycle(vector<int>& result) {
    unordered_map<int, int> idx;

    for (int i = 0; i < result.size(); i++) {
        idx[result[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
       for (const int& x : adj[i]) {
            if (idx[x] < idx[i]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
	setup();
	cin >> t;
	while (t--) {
		vector<int> prev_rank;
		vector<int> result;
		vector<int> idx;

		cin >> n;
		idx.resize(n + 1);
		for (int i = 0; i < n; i++) {
			int x;
			
			cin >> x;
			prev_rank.push_back(x);
			idx[x] = i;
		}
		for (int i = 0; i < n; i++) {
			int u = prev_rank[i];

			for (int j = i + 1; j < n; j++) {
				int v = prev_rank[j];

				adj[u].push_back(v);
			}
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			int u, v;

			cin >> u >> v;
			if (idx[u] < idx[v]) {
				swap(u, v);
			}
			adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
			adj[u].push_back(v);
		}

		result = topological_sort();
		
		if (has_cycle(result)) {
			cout << "IMPOSSIBLE\n";
		} else {
			for (const int& x : result) {
				cout << x << " ";
			}
			cout << "\n";
		}

		// clear
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		fill_n(&visited[1], n, false);
	}

	return 0;
}
