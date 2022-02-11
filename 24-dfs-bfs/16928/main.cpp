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

#define MAX		(100 + 1)

uint64_t m, n, t, k, v;
int arr[MAX], d[MAX];
bool visited[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	queue<int> qu;
	int u, v, w;

	setup();
	cin >> n >> m;
	while (n--) {
		cin >> u >> v;
		arr[u] = v;
	}
	while (m--) {
		cin >> u >> v;
		arr[u] = v;
	}

	qu.push(1);
	while (!qu.empty()) {
		u = qu.front();
		qu.pop();

		if (u == MAX - 1) {
			break;
		}
		for (int i = 1; i <= 6; i++) {
			w = (arr[u + i] != 0) ? arr[u + i] : u + i;
			if (!visited[w]) {
				visited[w] = true;
				qu.push(w);
				d[w] = d[u] + 1;
			}
		}
	}
	cout << d[MAX - 1] << "\n";

	return 0;
}
