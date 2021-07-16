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
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

#define MAX		1000000

uint64_t m, n, t, c;
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

bool test(int x) {
	int prev = arr[0], cnt = 1;

	for (int i = 1; i < n; i++) {
		if (arr[i] - prev >= x) {
			prev = arr[i];
			cnt++;
		}
		if (cnt >= c) {
			return true;
		}
	}
	return false;
}

int search(int left, int right) {
	int mid = (left + right) / 2 + 1;

	if (left >= right) {
		return left;
	}
	if (!test(mid)) {
		return search(left, mid - 1);
	} else {
		return search(mid, right);
	}
}

int main() {
	int left = INT_MAX, right = 0;

	setup();
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++) {
		left = min(left, arr[i + 1] - arr[i]);
	}
	cout << search(left, INT_MAX) << "\n";
	return 0;
}
