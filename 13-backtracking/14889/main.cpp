#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
using namespace std;

#define MAX		20
unsigned long long m, n, t;
int s[MAX + 1][MAX + 1], A[MAX + 1], B[MAX + 1], p[2];
bool inA[MAX + 1], visited[MAX + 1];
int minRes = INT_MAX;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void score(int k, int *arr, int *p, int &res) {
	if (k == 2) {
		res += s[arr[p[0]]][arr[p[1]]];
		res += s[arr[p[1]]][arr[p[0]]];
		return;
	}
	for (int i = (k == 0) ? 0 : p[k - 1]; i < n / 2; i++) {
		if (!visited[i]) {
			visited[i] = true;
			p[k] = i;
			score(k + 1, arr, p, res);
			visited[i] = false;
		}
	}
}

void backtrack(int k) {
	if (k == n / 2) {
		int idx = 0;

		for (int i = 0; i < n; i++) {
			if (!binary_search(A, A + k, i)) {
				B[idx++] = i;	
			}
		}
		int resA = 0, resB = 0;
		score(0, A, p, resA);
		fill_n(visited, MAX + 1, false);
		fill_n(p, 2, 0);
		score(0, B, p, resB);

		int res = abs(resA - resB);
		minRes = (res < minRes) ? res : minRes;
	}
	for (int i = (k == 0) ? 0 : A[k - 1]; i < n; i++) {
		if (!inA[i]) {
			inA[i] = true;
			A[k] = i;
			backtrack(k + 1);
			inA[i] = false;
		}
	}
}

int main() {
	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	backtrack(0);
	cout << minRes << "\n";
	return 0;
}
