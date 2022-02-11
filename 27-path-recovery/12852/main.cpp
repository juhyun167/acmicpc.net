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

#define MAX		(1000000 + 1)

int m, n, t, k, v;
int d[MAX], parent[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void search(int s) {
	queue<int> qu;
	
	fill_n(&d[0], MAX, INT_MAX);
	
	d[s] = 0;
	qu.push(s);
	while (!qu.empty()) {
		int u = qu.front();

		qu.pop();
		if (u == 1) {
			continue;
		}
		if (u % 3 == 0 && d[u / 3] > d[u] + 1) {
			d[u / 3] = d[u] + 1;
			parent[u / 3] = u;
			qu.push(u / 3);
		}
		if (u % 2 == 0 && d[u / 2] > d[u] + 1) {
			d[u / 2] = d[u] + 1;
			parent[u / 2] = u;
			qu.push(u / 2);
		}
		if (d[u - 1] > d[u] + 1) {
			d[u - 1] = d[u] + 1;
			parent[u - 1] = u;
			qu.push(u - 1);
		}
	}
}

void trace(int s, vector<int>& path) {
	int x = 1;

	while (x != s) {
		path.emplace_back(x);
		x = parent[x];
	}
	path.emplace_back(x);
	
	reverse(path.begin(), path.end());
}

int main() {
	int x;
	vector<int> path;

	setup();
	cin >> x;

	search(x);
	trace(x, path);

	cout << path.size() - 1 << "\n";
	for (const int& n : path) {
		cout << n << " ";
	}
	cout << "\n";

	return 0;
}
