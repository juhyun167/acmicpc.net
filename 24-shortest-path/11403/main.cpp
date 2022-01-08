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

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> d1[i][j];
			if (d1[i][j] == 0) {
				d1[i][j] = INF;
			}
		}
	}
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d2[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
			}
		}
		swap(d1, d2);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (0 < d1[i][j] && d1[i][j] < INF) {
				cout << "1 ";
			} else {
				cout << "0 ";
			}
		}
		cout << "\n";
	}

	return 0;
}
