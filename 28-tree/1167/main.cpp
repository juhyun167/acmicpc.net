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
unordered_map<int, int> w[MAX];
bool visited[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

pair<int, int> dfs(int u) {
	int max_d = 0, max_v = u;

	for (const int &v : adj[u]) {
		int temp_d, temp_v;

		if (!visited[v]) {
			visited[v] = true;
			tie(temp_d, temp_v) = dfs(v);
			if (max_d < w[u][v] + temp_d) {
				max_d = w[u][v] + temp_d;
				max_v = temp_v;
			}
		}
	}
	return { max_d, max_v };
}

int main() {
	int d, v;

	setup();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int s;

		cin >> s;
		while (true) {
			int t, weight;

			cin >> t;
			if (t == -1) {
				break;
			}
			cin >> weight;
			adj[s].emplace_back(t);
			adj[t].emplace_back(s);
			w[s][t] = w[s][t] = weight;
		}
	}

	visited[1] = true;
	tie(d, v) = dfs(1);

	fill_n(&visited[1], n, false);
	visited[v] = true;
	tie(d, v) = dfs(v);
	cout << d << "\n";

	return 0;
}
