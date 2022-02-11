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

bool test(int x) {
	uint64_t sum = 0;

	for (int i = 0; i < n; i++) {
		sum += (arr[i] - x > 0) ? arr[i] - x : 0;
	}
	return sum >= m;
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
	setup();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << search(0, *max_element(arr, arr + n)) << "\n";
	return 0;
}
