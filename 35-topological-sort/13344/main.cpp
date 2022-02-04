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

#define MAX		(50000 + 1)

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

template <typename T>
class disjoint_set {
    unordered_map<T, T> parent;
    unordered_map<T, int> rank;
    unordered_map<T, int> size;
    int count = 0;

    void link(T x, T y) {
        if (rank[x] > rank[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

public:
    void make_set(T x) {
        if (parent.count(x) == 0) {
            parent[x] = x;
            rank[x] = 0;
            size[x] = 1;
            count++;
        }
    }

    void union_set(T x, T y) {
        if (find_set(x) != find_set(y)) {
            link(find_set(x), find_set(y));
            count--;
        }
    }

    T find_set(T x) {
        if (x != parent[x]) {
            parent[x] = find_set(parent[x]);
        }

        return parent[x];
    }

    int count_sets() {
        return count;
    }

    int get_set_size(T x) {
        return size[find_set(x)];
    }
};

disjoint_set<int> ds;

void dfs(int u, vector<int>& result) {
    for (const int& w : adj[u]) {
        if (!visited[w]) {
            visited[w] = true;
            dfs(w, result);
        }
    }
    result.emplace_back(u);
}

vector<int> topological_sort(unordered_set<int>& verticies) {
    vector<int> result;
	unordered_set<int>::iterator it;

    for (it = verticies.begin(); it != verticies.end(); it++) {
		int u = *it;

        if (!visited[u]) {
            visited[u] = true;
            dfs(u, result);
        }
    }
    reverse(result.begin(), result.end());

    return result;
}

bool has_cycle(vector<int>& result, unordered_set<int>& verticies) {
	unordered_map<int, int> idx;
	unordered_set<int>::iterator it;

	for (int i = 0; i < result.size(); i++) {
		idx[result[i]] = i;
	}
	for (it = verticies.begin(); it != verticies.end(); it++) {
		int u = *it;

		for (const int& x : adj[u]) {
			if (idx[x] < idx[u]) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	unordered_set<int> verticies;
	vector<pair<int, int>> vec;
	vector<int> result;

	setup();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ds.make_set(i);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		char op;

		cin >> a >> op >> b;
		if (op == '=') {
			ds.union_set(a, b);
		} else {
			vec.emplace_back(make_pair(a, b));
		}
	}

	for (const pair<int, int>& p : vec) {
		int a = p.first, b = p.second;

		if (ds.find_set(a) == ds.find_set(b)) {
			cout << "inconsistent\n";
			return 0;
		}
		a = ds.find_set(a), b = ds.find_set(b);
		adj[a].emplace_back(b);
		verticies.insert(a);
		verticies.insert(b);
	}

	result = topological_sort(verticies);
	if (has_cycle(result, verticies)) {
		cout << "inconsistent\n";
	} else {
		cout << "consistent\n";
	}

	return 0;
}
