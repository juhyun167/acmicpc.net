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

#define MAX		(400000 + 1)

int m, n, t, k, v;
vector<int> adj[MAX];
int e[MAX], indeg[MAX];

struct node {
	int id, e;

	node() : id(0), e(0) {}
	node(int id, int e) : id(id), e(e) {}

	bool operator>(const node& other) const {
		return e > other.e;
	}
};

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int topological_sort() {
	priority_queue<node, vector<node>, greater<node>> pq;
	int num = n, ans = INT_MIN;

	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			pq.push(node(i, e[i]));
		}
	}

	while (!pq.empty()) {
		node u = pq.top();
		
		pq.pop();
		ans = max(ans, u.e + (--num));
		for (const int& w : adj[u.id]) {
			indeg[w]--;
			if (indeg[w] == 0) {
				pq.push(node(w, e[w]));
			}
		}
	}

	return ans;
}

int main() {
	vector<int> result;

	setup();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> e[i] >> m;
		for (int j = 0; j < m; j++) {
			int x;

			cin >> x;
			adj[i].push_back(x);
			indeg[x]++;
		}
	}

	cout << topological_sort() << "\n";

	return 0;
}
