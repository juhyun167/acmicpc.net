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
#define INF		(INT_MAX / 2)

int m, n, t, k, v;
int arr1[MAX][MAX], arr2[MAX][MAX];
int res[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	int (*d1)[MAX] = arr1;
	int (*d2)[MAX] = arr2;
	int minres = INT_MAX;
	vector<int> vec;
	
	setup();
	cin >> n >> m;
	fill_n(&arr1[0][0], MAX * MAX, INF);
	for (int i = 0; i <= n; i++) {
		arr1[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int u, v;

		cin >> u >> v;
		arr1[u][v] = arr1[v][u] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d2[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
			}
		}
		swap(d1, d2);
	}
	
	for (int i = 1; i <= n; i++) {
		int sum = 0;

		for (int j = 1; j <= n; j++) {
			sum += d1[i][j];
		}
		res[i] = sum;
	}
	minres = *min_element(&res[1], &res[n + 1]);
	for (int i = 1; i <= n; i++) {
		if (res[i] == minres) {
			vec.emplace_back(i);
		}
	}
	cout << *min_element(vec.begin(), vec.end()) << "\n";

	return 0;
}
