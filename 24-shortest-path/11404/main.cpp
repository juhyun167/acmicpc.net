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

int m, n, t, k, v;
int arr1[MAX][MAX], arr2[MAX][MAX];
const int INF = INT_MAX / 2;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	int (*d1)[MAX] = arr1, (*d2)[MAX] = arr2;

	setup();
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr1[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		
		cin >> a >> b >> c;
		arr1[a - 1][b - 1] = min(arr1[a - 1][b - 1], c);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					d2[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
				}
			}
		}
		swap(d1, d2);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d1[i][j] == INF) {
				cout << "0 ";
			} else {
				cout << d1[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}
