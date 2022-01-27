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
bool visited[MAX];
int d[MAX], parent[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

inline bool in_range(int x) {
	return 0 <= x && x < MAX;
}

int get_neighbor(int x, int i) {
	switch (i) {
		case 0:
			return x - 1;
		case 1:
			return x + 1;
		case 2:
			return 2 * x;
		default:
			return -1;
	}
}

void print_path() {
	vector<int> path;

	cout << d[k] << "\n";
	while (k != n) {
		path.emplace_back(k);
		k = parent[k];
	}
	path.emplace_back(n);

	for (auto it = path.rbegin(); it != path.rend(); it++) {
		cout << *it << " ";
	}
	cout << "\n";
}

void search() {
	queue<int> qu;

	visited[n] = true;
	d[n] = 0;
	qu.push(n);
	while (!qu.empty()) {
		int u = qu.front();

		qu.pop();
		if (u == k) {
			print_path();
			return;
		}
		for (int i = 0; i < 3; i++) {
			int w = get_neighbor(u, i);

			if (in_range(w) && !visited[w]) {
				visited[w] = true;
				d[w] = d[u] + 1;
				parent[w] = u;
				qu.push(w);
			}
		}
	}
}

int main() {
	setup();
	cin >> n >> k;

	fill_n(&d[0], MAX, INT_MAX);
	search();

	return 0;
}
