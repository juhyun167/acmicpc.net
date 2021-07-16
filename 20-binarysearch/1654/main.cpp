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

uint64_t m, n, t, k;
uint64_t arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

bool test(int x) {
	uint64_t sum = 0;

	for (int i = 0; i < k; i++) {
		sum += arr[i] / x;
	}
	return sum >= n;
}

uint64_t search(uint64_t left, uint64_t right) {
	uint64_t mid = (left + right) / 2 + 1;
	
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
	uint64_t left, right;

	setup();
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + k);

	left = 1;
	right = INT_MAX;
	cout << search(left, right) << "\n";
	return 0;
}
