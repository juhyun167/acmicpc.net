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

#define MAX		11

unsigned long long m, n, t;
int arr[MAX + 1];
int opMax[4], opCur[4];				// +, -, *, /
int maxRes = INT_MIN, minRes = INT_MAX;
string opSeq = "";

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

void backtrack(int k) {
	if (k == n - 1) {
		int res = arr[0];

		for (int i = 0; i < n - 1; i++) {
			switch (opSeq[i]) {
				case '+':
					res += arr[i + 1];
					break;
				case '-':
					res -= arr[i + 1];
					break;
				case '*':
					res *= arr[i + 1];
					break;
				case '/':
					res /= arr[i + 1];
					break;
			}
		}
		maxRes = (res > maxRes) ? res : maxRes;
		minRes = (res < minRes) ? res : minRes;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (opCur[i] < opMax[i]) {
			switch (i) {
				case 0:
					opSeq[k] = '+';
					break;
				case 1:
					opSeq[k] = '-';
					break;
				case 2:
					opSeq[k] = '*';
					break;
				case 3:
					opSeq[k] = '/';
					break;
			}
			opCur[i] += 1;
			backtrack(k + 1);
			opCur[i] -= 1;
		}
	}
}

int main() {
	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> opMax[i];
	}
	backtrack(0);
	cout << maxRes << "\n";
	cout << minRes << "\n";
	return 0;
}
