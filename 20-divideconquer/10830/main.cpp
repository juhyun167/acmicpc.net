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

#define MAX		5

unsigned long long m, n, t, k;

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void modmul(vector<vector<int>> &a, vector<vector<int>> &b,
				vector<vector<int>> &result, int modulus) {
	vector<vector<int>> _a = a, _b = b;

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result.size(); j++) {
			result[i][j] = 0;
		}
	}

	for (int i = 0; i < _a.size(); i++) {
		for (int j = 0; j < _b[0].size(); j++) {
			for (int t = 0; t < _b.size(); t++) {
				result[i][j] += _b[t][j] * _a[i][t] % modulus;
			}
		}
	}
}

void modpow(vector<vector<int>> &base, unsigned long long exp, 
			int modulus) {
	vector<vector<int>> result(n, vector<int>(n));

	// identity matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = (i == j) ? 1 : 0;
		}
	}

	while (exp > 0) {
		if (exp & 1) {
			modmul(result, base, result, modulus);
		}
		modmul(base, base, base, modulus);
		exp >>= 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] % modulus << " ";
		}
		cout << "\n";
	}
}

int main() {
	vector<vector<int>> a;
	unsigned long long b;

	setup();
	cin >> n >> b;
	a.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	modpow(a, b, 1000);
	return 0;
}
