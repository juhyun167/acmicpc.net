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
int arr[MAX + 1];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

uint64_t count(uint64_t num) {
	uint64_t cnt = 0;

	for (int i = 1; i <= n; i++) {
		cnt += min(num / i, n);
	}
	return cnt;
}

uint64_t search(uint64_t left, uint64_t right) {
	uint64_t mid = (left + right) / 2;

	if (left >= right) {
		return left;
	}
	if (count(mid) < k) {
		return search(mid + 1, right);
	} else {
		return search(left, mid);
	}
}

int main() {
	setup();
	cin >> n >> k;
	cout << search(1, n * n) << "\n";
	return 0;
}
