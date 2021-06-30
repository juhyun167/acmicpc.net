#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX		50

unsigned long long m, n, t;
char arr[MAX + 1][MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int count(int n, int m) {
	int cnt = 0, cnt2 = 0;

	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if ((i + j) % 2 == 0 && arr[i][j] != 'W') {
				cnt++;
			} else if ((i + j) % 2 == 0 && arr[i][j] != 'B') {
				cnt2++;
			}
			if ((i + j) % 2 == 1 && arr[i][j] != 'B') {
				cnt++;
			} else if ((i + j) % 2 == 1 && arr[i][j] != 'W') {
				cnt2++;
			}
		}
	}
	return min(cnt, cnt2);
}

int main() {
	int min = INT_MAX;

	setup();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			min = (count(i, j) < min) ? count(i, j) : min;
		}
	}
	cout << min << "\n";
	return 0;
}
