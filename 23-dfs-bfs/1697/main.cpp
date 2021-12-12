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

#define MAX		(100000 + 1)

uint64_t m, n, t, k, v;
int arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

inline bool check(int x) {
	return 0 <= x && x <= 100000;
}

int next(int x, int n) {
	if (n == 0) { return x - 1; }
	else if (n == 1) { return x + 1; }
	else { return 2 * x; }
}

int main() {
	queue<int> qu;
	vector<bool> visited(MAX, false);
	vector<int> d(MAX, 0);

	setup();
	cin >> n >> k;

	qu.push(n);
	while (!qu.empty()) {
		int u = qu.front();

		qu.pop();
		if (u == k) {
			cout << d[u] << "\n";
			break;
		}

		for (int i = 0; i < 3; i++) {
			int w = next(u, i);

			if (check(w) && !visited[w]) {
				visited[w] = true;
				d[w] = d[u] + 1;
				qu.push(w);
			}
		}
	}
		
	return 0;
}
