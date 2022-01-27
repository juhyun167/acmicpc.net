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

#define MAX		(500 + 1)

int m, n, t, k, v;
vector<vector<double>> a;		// augmented matrix

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void row_exchange(int r1, int r2) {
	for (int i = 0; i < n * 2; i++) {
		swap(a[r1][i], a[r2][i]);
	}
}

int main() {
	setup();
	cin >> n;
	a.resize(n, vector<double>(n * 2));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		for (int j = n; j < n * 2; j++) {
			a[i][j] = (j - n == i) ? 1 : 0;
		}
	}

	for (int j = 0; j < n; j++) {	// for every column
		double pivot;
		int i;

		// find leading entry which is not zero
		for (i = j; i < n; i++) {
			if (a[i][j] != 0) {
				row_exchange(i, j);
				break;
			}
		}
		if (i == n) {
			cout << "no inverse\n";
			return 0;
		}
		
		// gauss
		pivot = a[j][j];
		for (i = j + 1; i < n; i++) {
			double m = -a[i][j] / pivot;	// multiplier

			for (int k = 0; k < n * 2; k++) {
				a[i][k] += m * a[j][k];
			}
		}
		// jordan
		for (int i = j - 1; i >= 0; i--) {
			double m = -a[i][j] / pivot;	// multiplier

			for (int k = 0; k < n * 2; k++) {
				a[i][k] += m * a[j][k];
			}
		}
	}

	// divide by pivots
	for (int i = 0; i < n; i++) {
		double pivot = a[i][i];

		for (int j = 0; j < n * 2; j++) {
			a[i][j] /= pivot;
		}
	}

	// output
	for (int i = 0; i < n; i++) {
		for (int j = n; j < n * 2; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
