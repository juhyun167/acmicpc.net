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

#define MAX		15

unsigned long long m, n, t, cnt = 0;
int posX[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

bool check(int j, int k) {
	for (int i = 0; i < k; i++) {
		if (posX[i] == j || abs(k - i) == abs(j - posX[i])) {
			return false;
		}
	}
	return true;
}

void backtrack(int k) {
	if (k == n) {
		cnt += 1;
		return;
	}
	for (int j = 0; j < n; j++) {
		if (check(j, k)) {
			posX[k] = j;
			backtrack(k + 1);
		}
	}
}

int main() {
	setup();
	cin >> n;
	backtrack(0);
	cout << cnt << "\n";
	return 0;
}
