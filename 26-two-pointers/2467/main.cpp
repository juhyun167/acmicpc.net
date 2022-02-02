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
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue>
#include <list>
#include <utility>
#include <iomanip>
using namespace std;

#define MAX		(100000 + 1)

int m, n, t, k, v;
int arr[MAX];

void setup() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout << setprecision(10);
}

int main() {
	int l, r, result = INT_MAX;
	int ans1, ans2;

	setup();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	l = 0, r = n - 1;
	while (l < r) {
		if (abs(arr[l] + arr[r]) < result) {
			result = abs(arr[l] + arr[r]);
			ans1 = arr[l], ans2 = arr[r];
		}
		if (arr[l] + arr[r] < 0) {
			l++;
		} else if (arr[l] + arr[r] > 0) {
			r--;
		} else {
			break;
		}
	}

	cout << ans1 << " " << ans2 << "\n";

	return 0;
}
