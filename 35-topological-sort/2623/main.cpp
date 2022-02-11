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
	vector<int> result;

	setup();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		vector<int> vec;
		
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;

			cin >> x;
			vec.push_back(x);
		}
		for (int i = 0; i < k - 1; i++) {
			int u = vec[i], v = vec[i + 1];

			adj[u].push_back(v);
		}
	}

	result = topological_sort();
	
	if (has_cycle(result)) {
		cout << "0\n";
	} else {
		for (const int& x : result) {
			cout << x << "\n";
		}
	}

	return 0;
}
