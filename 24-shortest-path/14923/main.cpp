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

#define MAX		(100 + 1)

int m, n, t, k, v, r;
unordered_map<int, int> w[MAX];
int d[MAX], item[MAX], result[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void djkstra(int s) {
	auto compare = [](int &lhs, int &rhs) -> bool {
		return d[lhs] > d[rhs];
	};
    priority_queue<int, vector<int>, decltype(compare)>
        pq(compare);
    const int INF = INT_MAX / 2;

    // initialize
    fill_n(&d[1], n, INF);
    d[s] = 0;

    pq.push(s);
    while (!pq.empty()) {
        int u = pq.top();
        unordered_map<int, int>::iterator it;

        pq.pop();
        for (it = w[u].begin(); it != w[u].end(); it++) {
            // relaxation
            int v = it->first;

            if (d[v] > d[u] + w[u][v]) {
                d[v] = d[u] + w[u][v];
                pq.push(v);
            }
        }
    }
}

int main() {
	setup();
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 0; i < r; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		w[a][b] = w[b][a] = c;
	}

	for (int i = 1; i <= n; i++) {
		djkstra(i);
		for (int j = 1; j <= n; j++) {
			if (d[j] <= m) {
				result[i] += item[j];
			}
		}
	}
	
	cout << *max_element(&result[1], &result[n + 1]) << "\n";

	return 0;
}
