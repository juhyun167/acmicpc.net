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

#define MAX		(10000 + 1)

int m, n, t, k, v;
unordered_map<int, int> w[MAX];
vector<int> reverse_adj[MAX];
bool visited[MAX];

int f[MAX];			// finishing time
int l[MAX];			// length of path to each vertex

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void dfs(int u, int time, vector<int>& result) {
	unordered_map<int, int>::iterator it;
	f[u] = time;

    for (it = w[u].begin(); it != w[u].end(); it++) {
		int v = it->first, c = it->second;

        if (!visited[v]) {
            visited[v] = true;
            dfs(v, time + c, result);
        }
    }
    result.emplace_back(u);
}

vector<int> topological_sort(int s) {
    vector<int> result;

    for (int i = 0; i < n; i++) {
		int u = (s + i <= n) ? s + i : s + i - n;

        if (!visited[u]) {
            visited[u] = true;
            dfs(u, 0, result);
        }
    }
    reverse(result.begin(), result.end());

    return result;
}

int main() {
	int s, e;		// start, end
	vector<int> result;
	set<int> cities;
	int cnt = 0;

	setup();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		w[a][b] = c;
		reverse_adj[b].emplace_back(a);
	}
	cin >> s >> e;

	result = topological_sort(s);

	for (const int& x : result) {
		for (const int& u : reverse_adj[x]) {
			f[x] = max(f[x], f[u] + w[u][x]);
		}
		if (x == e) {
			break;
		}
	}
	cities.insert(e);

	// bfs
	queue<int> qu;
	fill_n(&visited[0], MAX, false);

	visited[e] = true;
	qu.push(e);
	while (!qu.empty()) {
		int u = qu.front();

		qu.pop();
		for (const int& x : reverse_adj[u]) {
			if (f[u] == f[x] + w[x][u] && !visited[x]) {
				visited[x] = true;
				cities.insert(x);
				qu.push(x);
			}
		}
	}

	set<int>::iterator it;
	set<int>::reverse_iterator rit;

	//for (it = cities.begin(); it != cities.end(); it++) {
		//cout << *it << " ";
	//}
	//cout << "\n";

	for (rit = cities.rbegin(); rit != cities.rend(); rit++) {
		int x = *rit;

		for (const int& u : reverse_adj[x]) {
			if (f[x] == f[u] + w[u][x]) {
				cnt++;
			}
		}
	}

	cout << f[e] << "\n";
	cout << cnt << "\n";

	return 0;
}
