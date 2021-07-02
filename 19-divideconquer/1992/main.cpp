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
#include <tuple>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

#define MAX		1000

unsigned long long m, n, t;
int arr[MAX + 1][MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

bool check(int k, int y, int x) {
	int type = -1;

	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k; j++) {
			if (type == -1) {
				type = arr[i][j];
			} else if (type != arr[i][j]) {
				return false;
			}
		}
	}
	cout << type;
	return true;
}

void recursion(int k, int y, int x) {
	if (k == 0) {
		return;
	}
	if (!check(k, y, x)) {
		cout << "(";
		recursion(k / 2, y, x);
		recursion(k / 2, y, x + k / 2);
		recursion(k / 2, y + k / 2, x);
		recursion(k / 2, y + k / 2, x + k / 2);
		cout << ")";
	}
}

int main() {
	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;

			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	recursion(n, 0, 0);
	cout << "\n";
	return 0;
}
